//Estados
#define ESTADO_BLINK    1
#define ESTADO_OFF      2
#define ESTADO_ON       3
#define ESTADO_TIEMPO   4

//Tareas por estado
void taskBlink();
void taskOff();
void taskOn();
void taskTime();

void cambioEstados();

void cambioEstados(char& estado){
  char in = Serial.read();
  switch(in){
    case 'b':
      estado = ESTADO_BLINK;
      break;
    case 'n':
      estado = ESTADO_OFF;
      break;
    case 'y':
      estado = ESTADO_ON;
      break;
    case 't':
      estado = ESTADO_TIEMPO;
      break;
    default:
      //estado = estado
      break;
  }
}

//Definicion de las tareas
void taskBlink(){
  bool estado = digitalRead(13);
  digitalWrite(13, !estado);
}
void taskOff(){
  digitalWrite(13, LOW);
}
void taskOn(){
  digitalWrite(13, HIGH);
}
void taskTime(){
  Serial.println(millis()/1000.0);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  static char estado = ESTADO_BLINK;
  if(Serial.available() > 0){
     cambioEstados(estado);
  }

  switch(estado){
    case ESTADO_BLINK:
        taskBlink();
      break;
    case ESTADO_OFF:
        taskOff();
      break;
    case ESTADO_ON:
        taskOn();
        
      break;
    case ESTADO_TIEMPO:
        taskTime();
      break;
  }
  delay(100);
}
