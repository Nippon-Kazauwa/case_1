#include "mbed.h"      //подключение библиотеки mbed
DigitalIn button1(A2); // кнопка 1
DigitalIn button2(A3); // кнопка 2
DigitalIn button3(D3); // кнопка 3
DigitalIn button4(D6); // кнопка 4
DigitalOut led(LED1);  // светодиод
DigitalOut relay(D4);  // реле
int main(){
    button1.mode(PullNone);         // включение подтягивающего резистора кнопки 1 button2.mode(PullNone); //включение подтягивающего резистора кнопки 2 button3.mode(PullNone); //включение подтягивающего резистора кнопки 3 button4.mode(PullNone); //включение подтягивающего резистора кнопки 4pu
    button2.mode(PullNone);         // включение подтягивающего резистора кнопки 1 button2.mode(PullNone); //включение подтягивающего резистора кнопки 2 button3.mode(PullNone); //включение подтягивающего резистора кнопки 3 button4.mode(PullNone); //включение подтягивающего резистора кнопки 4
    button3.mode(PullNone);         // включение подтягивающего резистора кнопки 1 button2.mode(PullNone); //включение подтягивающего резистора кнопки 2 button3.mode(PullNone); //включение подтягивающего резистора кнопки 3 button4.mode(PullNone); //включение подтягивающего резистора кнопки 4
    button4.mode(PullNone);         // включение подтягивающего резистора кнопки 1 button2.mode(PullNone); //включение подтягивающего резистора кнопки 2 button3.mode(PullNone); //включение подтягивающего резистора кнопки 3 button4.mode(PullNone); //включение подтягивающего резистора кнопки 4

    led = true;                     // горение светодиода
    relay = true;                   // закрытие замка
    int i = 0;                      // счетчик правильных цифр
    int j = 0;                      // позиция цифры
    int password[4] = {1,2,3,4}; // заданный пароль
    int code[4] = {0, 0, 0, 0};     // вводимая комбинация
    while (1){
        if (j < 4){ // позиция цифры меньше четырех
            if (button1 == 0){ // нажатие на кнопку 1
                code[j] = 1; // запись цифры 1 на текущую позицию
                j++;         // увеличение позиции
                wait_us(500e+3);
            }
            if (button2 == 0){ // нажатие на кнопку 2
                code[j] = 2; // запись цифры 2 на текущую позицию
                j++;         // увеличение позиции
                wait_us(500e+3);
            }
            if (button3 == 0){ // нажатие на кнопку 3
                code[j] = 3; // запись цифры 3 на текущую позицию
                j++;         // увеличение позиции
                wait_us(500e+3);
            }
            if (button4 == 0){ // нажатие на кнопку 4
                code[j] = 4; // запись цифры 4 на текущую позицию
                j++;         // увеличение позиции
                wait_us(500e+3);
            }
        }
        else{
            for (int k = 0; k < 4; k++){
                if (code[k] == password[k]) // проверка совпадения комбинации с паролем {
                    i++;                    // увеличение счетчика правильных цифр
                else{
                    i = 0; // обнуление счетчика правильных цифр
                }
            }
        }
        if (i == 4){ // равенство счетчика правильных цифр четырем
            relay = !relay; // открытие замка
            for (int l = 0; l < 10; l++){
                led = !led; // мигание светодиода
                wait_us(1000e+3);
            }
            led = true;     // горение светодиода
            relay = !relay; // закрытие замка
            i = 0;          // обнуление счетчика правильных цифр
        }
        j = 0; // обнуление позиции цифры
    }
    return 0;
}