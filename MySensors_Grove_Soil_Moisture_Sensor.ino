/**
 * The MySensors Arduino library handles the wireless radio link and protocol
 * between your home built sensors/actuators and HA controller of choice.
 * The sensors forms a self healing radio network with optional repeaters. Each
 * repeater and gateway builds a routing tables in EEPROM which keeps track of the
 * network topology allowing messages to be routed to nodes.
 *
 * Created by Henrik Ekblad <henrik.ekblad@mysensors.org>
 * Copyright (C) 2013-2015 Sensnology AB
 * Full contributor list: https://github.com/mysensors/Arduino/graphs/contributors
 *
 * Documentation: http://www.mysensors.org
 * Support Forum: http://forum.mysensors.org
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.
 *
 *******************************
 *
 * REVISION HISTORY
 * Version 1.0: GUILLOTON Laurent
 * Version 1.1 - 2017-07-03: Création du sketch initial
 *
 * DESCRIPTION
 *
 * Sketch gérant l'envoi des datas d'en capteur d'humidité de sol (Grove) avec un lien NRF24L01 Mysensors v2.0
 * For more information, please visit:
 * http://wiki.seeed.cc/Grove-Moisture_Sensor/
 *
 */

// Enable debug prints
#define MY_DEBUG

// Enable and select radio type attached
#define MY_RADIO_NRF24

#include "Arduino.h"
#include <Wire.h>
#include <SPI.h>
#include <MySensors.h>


// Sleep time between sensor updates (in milliseconds)
static const uint64_t UPDATE_INTERVAL = 30000;

#define CHILD_ID 0
int sensorPin = A0; // select the input pin for the potentiometer
int sensorValue = 0; // variable to store the value coming from the sensor7

MyMessage msg(CHILD_ID, V_LEVEL);


void presentation()
{
  // Send the sketch version information to the gateway
  sendSketchInfo("Soil Moisture Sensor", "1.1");

  // Register all sensors to gw (they will be created as child devices)
  present(CHILD_ID, S_MOISTURE);
}


void setup()
{

 }


void loop()
{
	sensorValue=analogRead(sensorPin);

    send(msg.set(sensorValue, 1));

  // Sleep for a while to save energy
  sleep(UPDATE_INTERVAL);
}
