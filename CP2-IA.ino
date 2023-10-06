#include <DHT.h>
#include <LiquidCrystal.h>

// Define os pinos do LCD
LiquidCrystal lcd(12, 11, 10, 9, 7, 5);  // RS, E, DB4, DB5, DB6, DB7

// Define o pino do sensor DHT11
#define DHTPIN 8
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  lcd.begin(16, 2);  // Inicializa o LCD com o número de colunas e linhas
  dht.begin();       // Inicializa o sensor DHT11
  Serial.begin(9600);
  
}

void loop() {
  // Limpa o LCD
  lcd.clear();
  
  // Lê a umidade e temperatura
  float umidade = dht.readHumidity();
  float temperatura = dht.readTemperature();

  Serial.print("Umidade= "); Serial.println(umidade);
  Serial.print("Temperatura= "); Serial.println(temperatura);
  
  lcd.setCursor(0, 0);  // Define a posição do cursor para a primeira linha
  
  if (isnan(umidade) || isnan(temperatura)) {
    lcd.print("Erro no DHT!");
  } else {
    lcd.print("UMIDADE: ");
    lcd.print(umidade, 1);  // Exibe com uma casa decimal
    lcd.print("%");

    lcd.setCursor(0, 1);  // Define a posição do cursor para a segunda linha
    lcd.print("TEMP: ");
    lcd.print(temperatura, 1);  // Exibe com uma casa decimal
  }

  delay(2000);  // Aguarda 2 segundos para a próxima leitura
}
