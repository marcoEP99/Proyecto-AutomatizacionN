//CODIGO CREADO POR ALGOBACK YOUTUBE CHANNEL
//CODIGO PARA SENSOR DE COLORES
#define ENA 10
#define IN1 11
#define IN2 12
#define ENB 3
#define IN3 4
#define IN4 2



#define S0 5
#define S1 6
#define S2 7
#define S3 8
#define OUT 9



void setup()   
{  
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Configurar los pines del sensor de colores TCS230 como entradas
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(OUT, INPUT);

  // Configurar el puerto serial
  Serial.begin(9600);

  // Configurar la resolución de color del sensor TCS230 a 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
}  
    
void loop() 
{ 
int R = getRojo();
delay(200);
int V = getVerde();
delay(200);
int A = getAzul();
delay(200);

Serial.print("Int R "+ String(R));
Serial.print("  --  Int V "+ String(V));
Serial.print("  --  Int Z "+ String(A));

  if (R < V && R < A && R > 12 && R <= 25 ){
Serial.print("  EL COLOR ES Amarillo");

     analogWrite(ENA, 240);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(ENB, 255);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  }
  


  if (R > V && R > A && R > 70 && R <= 99) {
    Serial.print("  EL COLOR ES verde");
     // Activar ambos motores
    analogWrite(ENA, 255);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(ENB, 255);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  }
 
  else
  {
    Serial.print("  EL COLOR NO HA SIDO REGISTRADO");

       // Desactivar ambos motores
    analogWrite(ENA, 255);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    analogWrite(ENB, 255);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);


  }
  Serial.println(" ");

}  



    
int getRojo(){
  //leer color rojo
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  int ROJO = pulseIn(OUT, LOW);
  return ROJO;
}

int getAzul(){
  //leer color azul
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  int AZUL = pulseIn(OUT, LOW);
  return AZUL;
}

int getVerde(){
  //leer color verde
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  int VERDE = pulseIn(OUT, LOW);
  return VERDE;
}