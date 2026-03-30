# Jawaban Pertanyaan Praktikum
## Modul Percabangan
1. Pada kondisi apa program masuk ke blok `if`?
Program masuk ke blok `if` ketika nilai:
```
timeDelay<=100
```
3. Pada kondisi apa program masuk ke blok `else`?

4. Apa fungsi dari perintah `delay(timeDelay)`?

5. Program jika diubah alurnya menjadi mati → lambat → cepat → reset (mati)
```
const int ledPin = 11;     
int timeDelay = 1000;      

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {

  digitalWrite(ledPin, HIGH);
  delay(timeDelay);

  digitalWrite(ledPin, LOW);
  delay(timeDelay);

  if (timeDelay > 200) {
    timeDelay -= 200;   // dari lambat → cepat
  } 
  else if (timeDelay > 100) {
    timeDelay = 500;    // dari cepat → sedang
  } 
  else {
    digitalWrite(ledPin, LOW);
    delay(3000);        // kondisi mati
    timeDelay = 1000;   // kembali ke awal
  }
}
```
