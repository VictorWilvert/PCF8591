#include "pcf8591.h"

PCF8591::PCF8591(const uint8_t& t_address) {
  
  //
  //
  //
  m_wire = &Wire;
  m_address = t_address;
  m_sda = SDA;
  m_scl = SCL;
  m_output_status = 0x00;

}

#if !defined(__AVR)  
PCF8591::PCF8591(const uint8_t& t_address,
		 const uint8_t& t_sda, 
		 const uint8_t& t_scl) {

  //
  //
  //
  m_wire = &Wire;
  m_address = t_address;
  m_sda = t_sda;
  m_scl = t_scl;
  m_output_status = 0x00;

}
#endif

void PCF8591::begin() {

  //
  //
  //
  if (TWCR == 0)
  {
#if !defined(__AVR)
    m_wire->begin(m_sda, m_scl);
#else
    m_wire->begin();
#endif
  }

}

uint8_t PCF8591::read(const uint8_t& t_channel, const uint8_t& t_input_type) {
  
  //
  //
  //
  m_wire->beginTransmission(m_address);

  //
  //
  //
  m_wire->write(m_output_status|t_input_type|0x04|t_channel);
  m_wire->endTransmission();

  //
  //
  //
  m_wire->requestFrom(m_address, (uint8_t)2);
  m_wire->read();
  uint8_t ret_val = m_wire->read();
  return ret_val;

}

PCF8591::Input PCF8591::readAll(const uint8_t& t_input_type) {

  //
  //
  //
  m_wire->beginTransmission(m_address);

  //
  //
  //
  m_wire->write(m_output_status|t_input_type|0x04);
  m_wire->endTransmission();

  //
  //
  //
  m_wire->requestFrom(m_address, (uint8_t)5);
  Input ret_val;
  m_wire->read();
  ret_val.channel_0 = m_wire->read();
  ret_val.channel_1 = m_wire->read();
  ret_val.channel_2 = m_wire->read();
  ret_val.channel_3 = m_wire->read();
  return ret_val;

}

void PCF8591::write(const uint8_t& t_value) {

  //
  // 
  //
  m_output_status = 0x40;

  //
  // 
  //
  m_wire->beginTransmission(m_address);
  m_wire->write(0x40);
  m_wire->write(t_value);
  m_wire->endTransmission();

}

void PCF8591::disableOutput() {

  //
  // 
  //
  m_output_status = 0x00;

  //
  // 
  //
  m_wire->beginTransmission(m_address);
  m_wire->write(0x00);
  m_wire->endTransmission();

}
