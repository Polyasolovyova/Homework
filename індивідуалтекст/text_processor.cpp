#include "text_processor.h"

void processText(char* text) {
    if (!(text[0] >= 'a' && text[0] <= 'z')) return; 

    int i = 0;
    while (text[i] >= 'a' && text[i] <= 'z') i++; 

    if (!(text[i] >= '0' && text[i] <= '9')) return; 

    while (text[i] >= '0' && text[i] <= '9') { 
        text[i] = '*';
        i++;
    }
}
