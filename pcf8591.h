#ifndef __PCF8591_H__
#define __PCF8591_H__

#include "Wire.h"
#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

//! PCF8591 8-bit A/D and D/A converter
/*!

*/

class PCF8591 {
public:

  //!
  /*! */
  struct Input {
    uint8_t channel_0; /*!< */
    uint8_t channel_1; /*!< */
    uint8_t channel_2; /*!< */
    uint8_t channel_3; /*!< */
  };

  //!
  /*! */
  enum InputType {
    SINGLE_ENDED_INPUT, /*!< */ 
    TREE_DIFFERENTIAL_INPUT, /*!< */
    TWO_SINGLE_ONE_DIFFERENTIAL_INPUT, /*!< */
    TWO_DIFFERENTIAL_INPUT /*!< */
  };

  //!
  /*! */
  enum Channel {
    CHANNEL_0 = 0x00, /*!< */ 
    CHANNEL_1 = 0x01, /*!< */
    CHANNEL_2 = 0x02, /*!< */
    CHANNEL_3 = 0x03  /*!< */
  };

  //!
  /*!
 
  */
  PCF8591(const uint8_t& t_address);

#if !defined(__AVR)
  
  //!
  /*!
  
  */ 
  PCF8591(const uint8_t& t_address, const uint8_t& t_sda, const uint8_t& t_scl);

#endif

  //!
  /*!
  
  */
  void begin();

  //!
  /*!
  
  */
  uint8_t read(const uint8_t& t_channel, const uint8_t& t_input_type);

  //!
  /*!
  
  */
  Input readAll(const uint8_t& t_input_type); 

  //!
  /*!
  
  */
  void write(const uint8_t& t_value);

  //!
  /*!
  
  */
  void disableOutput();

private:

  //!
  /*!
  
  */
  TwoWire* m_wire;
  
  //!
  /*!
  
  */
  uint8_t m_address;

  //!
  /*!
  
  */
  uint8_t m_sda;

  //!
  /*!
  
  */
  uint8_t m_scl;

  //!
  /*!
  
  */
  uint8_t m_output_status;

};

#endif

