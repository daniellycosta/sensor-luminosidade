#ifndef SaIoTController_h
#define SaIoTController_h

#include <Arduino.h>
#include<ArduinoJson.h>

typedef void (*func_pointer)(String); //necessario verif
class SaIoTController
{
private:
  String jConf;
  String key;
  //void (*func_pointer)(int); //ponteiro pra função
public:
  SaIoTController();
  SaIoTController(String _jsonConfig);
  SaIoTController(String _key, String _tClass);
  SaIoTController(String _key, String _tClass, String _tag); //campos obrigatorios p/ o server
  ~SaIoTController();

  String getKey(void); //unico necessário p se reportar ao server, fora o cadastro
  String getClass(void);
  String getTag(void);
  String getByField(String _field);

  void setJsonConfig(String _jConfExt); 
  String getJsonConfig(void); //pega todo o json de configuração pra ser enviado ao back

  void setAction(func_pointer _function);
};
#endif
