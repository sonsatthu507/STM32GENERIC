/****************************************************************************
 *
 * USBSerial core library for Arduino STM32 + HAL + CubeMX (HALMX).
 *
 * Copyright (c) 2016 by Vassilis Serasidis <info@serasidis.gr>
 * Home: http://www.serasidis.gr
 * email: avrsite@yahoo.gr
 *
 * Arduino_STM32 forum: http://www.stm32duino.com
 *
 * Permission to use, copy, modify, and/or distribute this software for
 * any purpose with or without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all copies.
 *
 * Some functions follow the sam and samd arduino core libray files.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
 * WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR
 * BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES
 * OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
 * WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,
 * ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS
 *
 ****************************************************************************/

#ifdef MENU_USB_SERIAL

#include <SerialUSB.h>
#include "variant.h"

// Constructors ////////////////////////////////////////////////////////////////
SerialUSBClass::SerialUSBClass(){
  // Make sure Rx ring buffer is initialized back to empty.
  rx_buffer.iHead = rx_buffer.iTail = 0;
  //tx_buffer.iHead = tx_buffer.iTail = 0;
}

void SerialUSBClass::init(void){
/* Re-enumerate the USB */
  volatile unsigned int i;

#ifdef USB_DISC_PIN
  pinMode(USB_DISC_PIN, OUTPUT);
  digitalWrite(USB_DISC_PIN, HIGH);
	for(i=0;i<512;i++);
  digitalWrite(USB_DISC_PIN, LOW);
#else
  //pinMode(USBDP_PIN, OUTPUT);
  //digitalWrite(USBDP_PIN, LOW);
	//for(i=0;i<512;i++);
  //digitalWrite(USBDP_PIN, HIGH);

  
  pinMode(PA12, OUTPUT);
  digitalWrite(PA12, LOW);
  //HAL_Delay(1000);
  for(i=0;i<512;i++){};
  digitalWrite(PA12, HIGH);
  //HAL_Delay(1000);
  for(i=0;i<512;i++){};
#endif
  MX_USB_DEVICE_Init();
}


void SerialUSBClass::begin(uint32_t baud_count){
  init();
  // suppress "unused parameter" warning
	(void)baud_count;
}

void SerialUSBClass::begin(uint32_t baud_count, uint8_t config){
  init();
	//suppress "unused parameter" warning
	(void)baud_count;
	(void)config;
}

void SerialUSBClass::end(void){

}


int SerialUSBClass::availableForWrite(void){
  //return (CDC_SERIAL_BUFFER_SIZE - available());
  //return (uint32_t)(CDC_SERIAL_BUFFER_SIZE + tx_buffer.iHead - tx_buffer.iTail) % CDC_SERIAL_BUFFER_SIZE;
}


int SerialUSBClass::available(void){
  return (uint32_t)(CDC_SERIAL_BUFFER_SIZE + rx_buffer.iHead - rx_buffer.iTail) % CDC_SERIAL_BUFFER_SIZE;
}

int SerialUSBClass::peek(void)
{
  if ( rx_buffer.iHead == rx_buffer.iTail )
    return -1;

  return rx_buffer.buffer[rx_buffer.iTail];
}

int SerialUSBClass::read(void)
{
  // if the head isn't ahead of the tail, we don't have any characters
  if ( rx_buffer.iHead == rx_buffer.iTail )
    return -1;

  uint8_t uc = rx_buffer.buffer[rx_buffer.iTail];
  rx_buffer.iTail = (unsigned int)(rx_buffer.iTail + 1) % CDC_SERIAL_BUFFER_SIZE;

  return uc;
}

void SerialUSBClass::flush(void){
  //It's not implemented yet.
}

size_t SerialUSBClass::write(const uint8_t *buffer, size_t size){
   unsigned long timeout=millis()+5;
  if(hUsbDeviceFS.dev_state == USBD_STATE_CONFIGURED)
  {
    while(millis()<timeout)
   {
      if(CDC_Transmit_FS((uint8_t*)buffer, size) == USBD_OK)
     {
         return size;
      }
    }
  }
  
  return 0;


/*   uint8_t i;

  if(hUsbDeviceFS.dev_state == USBD_STATE_CONFIGURED){

    //HAL_NVIC_DisableIRQ(USB_LP_CAN1_RX0_IRQn);
    for(i=0;i<200;i++)
      if(CDC_Transmit_FS((uint8_t*)buffer, size) == USBD_OK){
        return size;
        //break;
      }


    //HAL_NVIC_EnableIRQ(USB_LP_CAN1_RX0_IRQn);
  }
  return 0; */
}

size_t SerialUSBClass::write(uint8_t c) {
  return write(&c, 1);
}

void SerialUSBClass::CDC_RxHandler (uint8_t* Buf, uint16_t Len){

  for(uint16_t i=0;i<Len;i++){
    if(available() < (CDC_SERIAL_BUFFER_SIZE - 1)){
      rx_buffer.buffer[rx_buffer.iHead] = *Buf++;
      rx_buffer.iHead = (uint16_t)(rx_buffer.iHead + 1) % CDC_SERIAL_BUFFER_SIZE;
    }else
      break;
  }
}


// This operator is a convenient way for a sketch to check whether the
// port has actually been configured and opened by the host (as opposed
// to just being connected to the host).  It can be used, for example, in
// setup() before printing to ensure that an application on the host is
// actually ready to receive and display the data.
// We add a short delay before returning to fix a bug observed by Federico
// where the port is configured (lineState != 0) but not quite opened.
SerialUSBClass::operator bool()
{
	// this is here to avoid spurious opening after upload
	if (millis() < 500)
		return false;

	bool result = false;

/* 	if (_usbLineInfo.lineState > 0)
	{
		result = true;
	}

	delay(10); */
	return result;
}

uint32_t SerialUSBClass::baud() {
	//return _usbLineInfo.dwDTERate;
  return 0;
}

uint8_t SerialUSBClass::stopbits() {
	//return _usbLineInfo.bCharFormat;
  return 0;
}

uint8_t SerialUSBClass::paritytype() {
	//return _usbLineInfo.bParityType;
  return 0;
}

uint8_t SerialUSBClass::numbits() {
	//return _usbLineInfo.bDataBits;
  return 0;
}

bool SerialUSBClass::dtr() {
	//return _usbLineInfo.lineState & 0x1;
  return 0;
}

bool SerialUSBClass::rts() {
	//return _usbLineInfo.lineState & 0x2;
  return 0;
}


extern PCD_HandleTypeDef hpcd_USB_FS;
extern PCD_HandleTypeDef hpcd_USB_OTG_FS;

//F1
extern "C" void USB_LP_CAN1_RX0_IRQHandler(void) {
  HAL_PCD_IRQHandler(&hpcd_USB_FS);
}
//F4
extern "C" void OTG_FS_IRQHandler(void) {
  HAL_PCD_IRQHandler(&hpcd_USB_OTG_FS);
}
//L0
extern "C" void USB_IRQHandler(void) {
  HAL_PCD_IRQHandler(&hpcd_USB_FS);
}

extern "C" void USBSerial_Rx_Handler(uint8_t *data, uint16_t len){ 
  SerialUSB.CDC_RxHandler(data, len); 
}

SerialUSBClass SerialUSB;

#endif
