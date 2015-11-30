#include <VirtualWire.h>
//const int LED = 13;
const int RX = 3;

void setup() {
    // Comunicacao com o Serial Monitor
    Serial.begin(9600);

    // Inicializando E/S do receptor
    vw_set_rx_pin(RX);
    // vw_set_ptt_inverted(true); // Requerido para DR3100
    vw_setup(2000); // Bits por segundo 
    vw_rx_start(); // Inicia a recepcao
}

void loop() {
    // uint8_t é o mesmo que um byte .
    // seu atalho para: um tipo de inteiro não assinado de comprimento 8 bits
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;
    if (vw_get_message(buf, &buflen)) { // Sem bloqueios na recepcao       
        char SensorCharMsg[10]; // conteudo da transmissao
      
        for (int i = 0; i <= buflen; i++) {
            SensorCharMsg[i] = (char)buf[i];
        }
    //verifica se terminou a transmissao
        SensorCharMsg[buflen] = '\0';
        
        Serial.print("$");
        Serial.print(SensorCharMsg);
        Serial.print("#");
        delay(3000);
    }
}
