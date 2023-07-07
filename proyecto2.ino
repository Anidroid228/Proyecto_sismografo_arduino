Código #2



# include <Wire.h>  //Incluimos Libreria

const int MPU = 0x68;               //Dirección predeterminada de I2C para MPU 6050
int16_t AcX, AcY, AcZ, JK, JJ, JI;  //acelerometro variables, Giroscipio variables
int rit1 = 3276, rit2 = 6553, rit3 = 9830, rit4 = 13106;
int rit5 = 16383, rit6 = 19660, rit7 = 22936, rit8 = 26213;
int rit9 = 29490, rit10 = 32767;
int espera = 500;
int led3rojo = A2;
int led2amarillo = A1;
int led1verde = A0;
int buz1 = 7;  //alarma

void setup() {
  Wire.begin();                 // Inicialización de la biblioteca
  Wire.beginTransmission(MPU);  // Comenzar transmisión a MPU
  Wire.write(0x6B);             // registro PWR_MGMT_1
  Wire.write(0);                // MPU-6050 al modo de inicio
  Wire.endTransmission(true);
  Serial.begin(9600);

  //Configara el pin en modo entrada-salida
  pinMode(led3rojo, OUTPUT);
  pinMode(led2amarillo, OUTPUT);
  pinMode(led1verde, OUTPUT);
  pinMode(buz1, OUTPUT);
}

void loop() {
  Wire.beginTransmission(MPU);      // Iniciar Transferencia
  Wire.write(0x3B);                 // registra 0x3B (ACCEL_XOUT_H), registra datos en cola.
  Wire.endTransmission(false);      // mantener la conexión
  Wire.requestFrom(MPU, 14, true);  // Solicitar datos a MPU
  //Lee byte a byte
  AcX = Wire.read() << 8 | Wire.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)
  AcY = Wire.read() << 8 | Wire.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  AcZ = Wire.read() << 8 | Wire.read();  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)

  //Buzz

  if(AcX>=rit7){
    digitalWrite(buz1, HIGH);
  }else{
    digitalWrite(buz1, LOW);
  }
  if(AcY>=rit7){
    digitalWrite(buz1, HIGH);
  }else{
    digitalWrite(buz1, LOW);
  }
  if(AcZ>=rit7){
    digitalWrite(buz1, HIGH);
  }else{
    digitalWrite(buz1, LOW);
  }

  //Condicion para encender led1 y buzzer
  if (AcX > rit1 && AcX < rit2) {
    analogWrite(led1verde, 60);
    analogWrite(led2amarillo, 0);
    analogWrite(led3rojo, 0);
  }
  if (AcX > rit2 && AcX < rit3) {
    analogWrite(led1verde, 120);
    analogWrite(led2amarillo, 0);
    analogWrite(led3rojo, 0);
  }
  if (AcX > rit3 && AcX < rit4) {
    analogWrite(led1verde, 255);
    analogWrite(led2amarillo, 0);
    analogWrite(led3rojo, 0);
  }
  if (AcX > rit4 && AcX < rit5) {
    analogWrite(led2amarillo, 60);
    analogWrite(led1verde, 0);
    analogWrite(led3rojo, 0);
  }
  if (AcX > rit5 && AcX < rit6) {
    analogWrite(led2amarillo, 120);
    analogWrite(led1verde, 0);
    analogWrite(led3rojo, 0);
  }
  if (AcX > rit6 && AcX < rit7) {
    analogWrite(led2amarillo, 255);
    analogWrite(led1verde, 0);
    analogWrite(led3rojo, 0);
  }
  if (AcX > rit7 && AcX < rit8) {
    analogWrite(led3rojo, 60);
    analogWrite(led2amarillo, 0);
    analogWrite(led1verde, 0);
  }
  if (AcX > rit8 && AcX < rit9) {
    analogWrite(led3rojo, 120);
    analogWrite(led2amarillo, 0);
    analogWrite(led1verde, 0);
  }
  if (AcX > rit9 && AcX <= rit10) {
    analogWrite(led3rojo, 255);
    analogWrite(led2amarillo, 0);
    analogWrite(led1verde, 0);
  }

  //Para Y

  if (AcY > rit1 && AcY < rit2) {
    analogWrite(led1verde, 60);
    analogWrite(led2amarillo, 0);
    analogWrite(led3rojo, 0);
  }

  if (AcY > rit2 && AcY < rit3) {
    analogWrite(led1verde, 120);
    analogWrite(led2amarillo, 0);
    analogWrite(led3rojo, 0);
  }

  if (AcY > rit3 && AcY < rit4) {
    analogWrite(led1verde, 255);
    analogWrite(led2amarillo, 0);
    analogWrite(led3rojo, 0);
  }

  if (AcY > rit4 && AcY < rit5) {
    analogWrite(led2amarillo, 60);
    analogWrite(led1verde, 0);
    analogWrite(led3rojo, 0);
  }

  if (AcY > rit5 && AcY < rit6) {
    analogWrite(led2amarillo, 120);
    analogWrite(led1verde, 0);
    analogWrite(led3rojo, 0);
  }

  if (AcY > rit6 && AcY < rit7) {
    analogWrite(led2amarillo, 255);
    analogWrite(led1verde, 0);
    analogWrite(led3rojo, 0);
  }

  if (AcY > rit7 && AcY < rit8) {
    analogWrite(led3rojo, 60);
    analogWrite(led2amarillo, 0);
    analogWrite(led1verde, 0);
  }

  if (AcY > rit8 && AcY < rit9) {
    analogWrite(led3rojo, 120);
    analogWrite(led2amarillo, 0);
    analogWrite(led1verde, 0);
  }

  if (AcY > rit9 && AcY <= rit10) {
    analogWrite(led3rojo, 255);
    analogWrite(led2amarillo, 0);
    analogWrite(led1verde, 0);
  }

  if (AcZ > rit1 && AcZ < rit2) {
    analogWrite(led1verde, 60);
    analogWrite(led2amarillo, 0);
    analogWrite(led3rojo, 0);
  }

  if (AcZ > rit2 && AcZ < rit3) {
    analogWrite(led1verde, 120);
    analogWrite(led2amarillo, 0);
    analogWrite(led3rojo, 0);
  }

  if (AcZ > rit3 && AcZ < rit4) {
    analogWrite(led1verde, 255);
    analogWrite(led2amarillo, 0);
    analogWrite(led3rojo, 0);
  }

  if (AcZ > rit4 && AcZ < rit5) {
    analogWrite(led2amarillo, 60);
    analogWrite(led1verde, 0);
    analogWrite(led3rojo, 0);
  }

  if (AcZ > rit5 && AcZ < rit6) {
    analogWrite(led2amarillo, 120);
    analogWrite(led1verde, 0);
    analogWrite(led3rojo, 0);
  }

  if (AcZ > rit6 && AcZ < rit7) {
    analogWrite(led2amarillo, 255);
    analogWrite(led1verde, 0);
    analogWrite(led3rojo, 0);
  }

  if (AcZ > rit7 && AcZ < rit8) {
    analogWrite(led3rojo, 60);
    analogWrite(led2amarillo, 0);
    analogWrite(led1verde, 0);
  }

  if (AcZ > rit8 && AcZ < rit9) {
    analogWrite(led3rojo, 120);
    analogWrite(led2amarillo, 0);
    analogWrite(led1verde, 0);
  }

  if (AcZ > rit9 && AcZ <= rit10) {
    analogWrite(led3rojo, 255);
    analogWrite(led2amarillo, 0);
    analogWrite(led1verde, 0);
  }
}
