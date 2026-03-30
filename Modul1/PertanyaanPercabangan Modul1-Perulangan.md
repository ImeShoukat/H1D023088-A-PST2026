# Praktikum Sistem Tertanam - Modul 1 Perulangan
## Jawaban Pertanyaan Praktikum 
### 1. Gambarkan rangkaian schematic 5 LED running yang digunakan pada percobaan!
Rangkaian tediri dari 4 LED yang dihubungkan ke pin digital Arduino (6-9). Setiap katoda anoda LED dihubungkan secara seri tanpa resistor pada breadboard yang kemudian dihubungkan ke pin 6-9 menggunakan kabel jumper. Katoda LED kemudian dihubungkan ke GND.
Konfigurasi rangkaian sebagai berikut:
| No | Pin | Keterangan        |
|----|-----|-------------------|
| 1  | 9   | LED hijau 1       |
| 2  | 8   | LED hijau 2       |
| 3  | 7   | LED kuning        |
| 3  | 6   | LED merah         |

### 2. Jelaskan bagaimana program membuat efek LED berjalan dari kiri ke kanan!
Efek LED berjalan dari kiri ke kanan dibuat menggunakan struktur perulangan for dengan pola kenaikan nilai (increment). Program dimulai dari pin dengan nomor terkecil (misalnya pin 6) hingga pin terbesar (misalnya pin 9).
Contoh perulangan yang digunakan:
```cpp
for (int ledPin = 6; ledPin < 10; ledPin++){
  digitalWrite(ledPin, HIGH); 
  delay(timer); 
  digitalWrite(ledPin, LOW);
}
```
Pada setiap iterasi, LED pada pin yang sedang aktif akan dinyalakan menggunakan `digitalWrite(ledPin, HIGH)`, kemudian diberikan jeda waktu menggunakan `delay(timer)`, lalu dimatikan kembali dengan `digitalWrite(ledPin, LOW)` sebelum berpindah ke LED berikutnya.
Proses ini dilakukan secara berurutan dari pin terkecil ke pin terbesar sehingga menghasilkan efek visual LED yang tampak bergerak dari kiri ke kanan.
### 3. Jelaskan bagaimana program membuat LED kembali dari kanan ke kiri!
Efek LED kembali dari kanan ke kiri dibuat menggunakan struktur perulangan for dengan pola penurunan nilai (decrement), yaitu dari pin terbesar ke pin terkecil.
```cpp
for (int ledPin = 9; ledPin >= 6; ledPin--) { 
  digitalWrite(ledPin, HIGH); 
  delay(timer); 
  digitalWrite(ledPin, LOW); 
} 
```
Perulangan dimulai dari pin terbesar (pin 9) kemudian berkurang hingga pin terkecil (pin 6). Pada setiap iterasi, LED dinyalakan menggunakan `digitalWrite(ledPin, HIGH)`, kemudian diberikan jeda waktu menggunakan `delay(timer)`, lalu dimatikan kembali dengan `digitalWrite(ledPin, LOW)`.

Karena urutan pin berjalan dari besar ke kecil, maka LED akan menyala secara berurutan dari kanan ke kiri. Hal ini menghasilkan efek visual LED yang tampak kembali ke arah semula.
### 4. Buatkan program agar LED menyala tiga LED kanan dan tiga LED kiri secara bergantian
dan berikan penjelasan disetiap baris kode nya dalam bentuk README.md!

