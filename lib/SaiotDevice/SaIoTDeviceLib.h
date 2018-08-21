#ifndef SaIoTDeviceLib_h
#define SaIoTDeviceLib_h
#include <Arduino.h>
#include "SaIoTSensor.h"
#include "SaIoTController.h"

#define maxSensors 5
#define maxControllers 1
//FALTA PENSAR NOS CONTROLADORES, NA HORA DO SUBSCRIBE
enum protocol
{
  WS,
  MQTT,
  HTTP
};
//typedef void (*fncpt)(String); //ponteiro pra função

class SaIoTDeviceLib
{
private:

  /*
    Tudo que for do device deve ser guardado na EEPROM futuramente, pra caso de atualização via OTA 
  */
  String name;
  String serial;
  String token;
  String email; 
  
  protocol _protocol = WS; //olhar dps

  unsigned int qtdSensors = 0;
  unsigned int qtdControllers = 0;
  SaIoTSensor *sensors[maxSensors];
  SaIoTController *controllers[maxControllers];
public:
  /* criar um construtor  e passar a start para o produto talvez*/
  //Editar após discussão de conexão
  SaIoTDeviceLib(String _name, String _serial, String _email);
  SaIoTDeviceLib(String _name, String _serial);
  SaIoTDeviceLib();

  void setToken(String _token);
  void setEmail(String _email);
  void handle(void);

  String getName();
  String getSerial();
  String getToken();
  String getEmail();
  String getProtocol();

  int getNSensors();
  int getNControllers();

  String makeJconf();

  void addSensor(SaIoTSensor &newSensor);
  /*void addSensor(String _key, int _deadbandMin, int _deadbandMax, int _timeout, int _resolution, bool _isAcumm, String _label, String _unit);
  void addSensor(String _key, String _unit);*/

  void addController(SaIoTController &newController);
  /*void addController(String _key, String _type);
  void addController(String _key, String _type, String _tag, String _description, double _min, double _step, double _max);*/
};
#endif
