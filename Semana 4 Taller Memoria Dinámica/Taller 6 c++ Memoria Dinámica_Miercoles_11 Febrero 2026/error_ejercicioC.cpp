int* funcionMala() {
    int x = 50; 
    return &x;  //Estás devolviendo un puntero a memoria inválida.
}


