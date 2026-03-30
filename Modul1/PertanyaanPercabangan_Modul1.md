# Praktikum Sistem Tertanam - Modul 1 Percabangan
## Jawaban Pertanyaan Praktikum 
### 1. Pada kondisi apa program masuk ke blok `if`?
Program masuk ke blok `if` ketika nilai:
```cpp
timeDelay<=100
```
Kondisi inin menunjukan bahwa LED telah mencapai kecepatan maksimum, sehingga program melakukan reset
### 2. Pada kondisi apa program masuk ke blok `else`?
Program masuk ke blok `ēlse` ketika:
```cpp
timeDelay > 100
```
Pada kondisi ini, LED masih dalam keadaan lambat atau sedang, sehingga delay akan terus dikurangi untuk mempercepat kedipan LED.
### 3. Apa fungsi dari perintah `delay(timeDelay)`?
Perintah `delay(timeDelay)` berfungsi untuk memberikan jeda waktu sesuai nilai `timeDelay`. Nilai ini menentukan cepat atau lambatnya LED berkedip, di mana semakin besar nilainya maka LED semakin lambat, dan semakin kecil nilainya maka LED semakin cepat
### 4. Program jika diubah alurnya menjadi mati → lambat → cepat → sedang -> mati
Apabila program yang awal alurnya mati-> lambat -> cepat -> riset -> mati, diubah menjadi mati → lambat → cepat → sedang -> mati
**Kode Program**
```cpp
const int ledPin = 11; // pake pin 11 buat LED   
int timeDelay = 1000;      

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {

  digitalWrite(ledPin, HIGH);
  delay(timeDelay);

  digitalWrite(ledPin, LOW);
  delay(timeDelay);

  // percabangan perubahan kecepatan
  if (timeDelay > 500) {
    timeDelay -= 200;   // dari lambat → cepat
  } 
  else if (timeDelay > 200) {
    timeDelay = 500;    // dari cepat → sedang
  } 
  else {
    timeDelay = 0;      // kondisi mati
  }

  // Hentikan program saat sudah mati
  if (timeDelay == 0) {
    digitalWrite(ledPin, LOW); // pastikan LED mati
    while(true);               // stop permanen
  }
}
```
Dari kode tersebut, dapat dilihat bahwa program dimulai dengan delay sebesar 1000 ms (1 detik) sehingga LED berkedip lambat. Selanjutnya, nilai delay dikurangi secara bertahap sehingga kecepatan kedipan LED meningkat. Setelah mencapai kondisi tertentu, kecepatan diubah menjadi sedang sebelum akhirnya LED dimatikan secara permanen. Pada tahap akhir, program dihentikan sehingga LED tetap dalam kondisi mati dan tidak kembali ke kondisi awal.

**Penjelasan Kode per-line**
#### - Menentukan Pin
```cpp
const int ledPin = 11;
```
Menentukan pin 11 sebagai pin LED yang nilainya tidak akan berubah selama program berjalan
#### - Deklarasi Variable
```cpp
int timeDelay = 1000;
```
Menyimpan nilai delay awal (1000ms) untuk mengatur kecepatan kedipan LED
#### - Inisialisasi Awal Program
```cpp
void setup () {...}
```
Akan dijalankan sekali saat Arduino pertama kali menyala
#### - Konfigurasi Pin
```cpp
pinMode(ledPin, OUTPUT);
```
Mengatur pin LED sebagai output agar dapat mengirim sinyal listrik.
#### - Fungsi Perulangan
```cpp
void loop() {...}
```
Semua kode di dalamnya akan dijalankan terus-menerus
#### - Output untuk menyalakan LED
```cpp
digitalWrite(ledPin,HIGH);
```
Memberikan logika HIGH sehingga LED menyala.
#### - Penundaan Waktu
```cpp
delay(timeDelay);
```
Memberikan jeda sesuai nilai `timeDelay`.
#### - Output untuk mematikan LED
```cpp
digitalWrite(ledPin,LOW);
```
Memberikan logika LOW sehingga LED mati.
#### - Penundaan Waktu
```cpp
delay(timeDelay);
```
Memberikan jeda saat LED dalam kondisi mati.
#### - Percabangan kondisi (if)
```cpp
if (timeDelay > 500) { ... }
```
Mengecek apakah delay masih besar (LED masih lambat)
#### - Operasi aritmatika dalam percabangan kondisi
```cpp
timeDelay -= 200;
```
Mengurangi nilai delay agar menjadi lebih cepat
#### - Percabangan else if
```cpp
else if (timeDelay > 200) {...}
```
Mengecek kondisi transisi dari cepat ke sedang
#### - Assignment dalam else if
```cpp
timeDelay = 500;
```
Mengatur delay ke nilai sedang (500ms)

#### - Percabangan else
```cpp
else {...}
```
Dijalankan jika kondisi sebelumnya tidak terpenuhi
#### - Assignment dalam else
```cpp
timeDelay = 0;
```
Mengubah delay menjadi 0 sebagai tanda kondisi mati.
#### - Percabangan kondisi
```cpp
if (timeDelay == 0){...}
```
Mengecek apakah program sudah mencapai kondisi akhir.
#### - Output digital
```cpp
digitalWrite(ledPin,LOW);
```
Memastikan LED dalam kondisi mati
#### - Perulangan tak hingga
```cpp
while(true);
```
Menghentikan program secara permanen agar tidak kembali ke awal.

### Kesimpulan
Program menggunakan percabangan untuk mengatur perubahan kecepatan LED dari lambat, cepat, hingga sedang, kemudian berhenti pada kondisi mati. Perulangan digunakan untuk menjalankan program secara terus-menerus, dan `while(true)` digunakan untuk menghentikan program agar tidak kembali ke kondisi awal.


