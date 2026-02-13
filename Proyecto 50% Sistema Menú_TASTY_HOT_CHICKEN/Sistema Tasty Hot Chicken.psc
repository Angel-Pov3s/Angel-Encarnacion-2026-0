Algoritmo TastyHotChickenPedido
    // ==========================================
    // CONFIGURACIÓN INICIAL Y VARIABLES
    // ==========================================
    // Variables para datos básicos y bucles
    Definir nombreUsuario, continuar, nombreProductoActual Como Caracter
    Definir totalGeneral, precioUnitarioActual, subtotalLinea Como Real
    Definir opcionCategoria, opcionProducto, cantidadActual, contadorItems Como Entero
    Definir categoriaValida, productoValido Como Logico
    
    // Variables para validación del nombre
    Definir i, LongitudNombre Como Entero
    Definir caracterActual Como Caracter
    Definir nombreSoloLetras Como Logico
    
    // --- ARREGLOS PARA EL RESUMEN FINAL ---
    // Capacidad para 50 ítems distintos en un solo pedido
    Dimension listaNombres[50]
    Dimension listaCantidades[50]
    Dimension listaSubtotales[50]
    
    totalGeneral <- 0
    contadorItems <- 0 
    continuar <- "S"
    
    // ==========================================
    // 1. BIENVENIDA E INGRESO DEL NOMBRE (VALIDADO)
    // ==========================================
    Escribir "======================================"
    Escribir "   Bienvenidos a Tasty Hot Chicken"
    Escribir "======================================"
    Escribir ""
    
    Repetir
        Escribir "Por favor, ingrese su nombre (solo letras):"
        Leer nombreUsuario
        
        // Inicializamos las variables de control para esta vuelta
        nombreSoloLetras <- Verdadero
        LongitudNombre <- Longitud(nombreUsuario)
        
        // Validación 1: No puede estar vacío
        Si LongitudNombre = 0 Entonces
            nombreSoloLetras <- Falso
            Escribir ">>> Error: El nombre no puede estar vacío."
        SiNo
            // Validación 2: Bucle para revisar carácter por carácter
            Para i <- 1 Hasta LongitudNombre Con Paso 1 Hacer
                // Convertimos a mayúscula para facilitar la comparación
                caracterActual <- Mayusculas(Subcadena(nombreUsuario, i, i))
                
                // Verificamos si NO es una letra (A-Z) Y NO es un espacio (" ")
                // Nota: Esta validación básica puede no aceptar tildes o Ñ dependiendo de la config de PSeInt.
                // Si se requiere aceptar Ñ, agregar: ... O caracterActual = "Ñ"
                Si NO ((caracterActual >= "A" Y caracterActual <= "Z") O caracterActual = " ") Entonces
                    nombreSoloLetras <- Falso
                    // Si encontramos un error, forzamos la salida del bucle Para
                    i <- LongitudNombre 
                FinSi
            Fin Para
            
            Si NO nombreSoloLetras Entonces
				Escribir ">>> Error: El nombre contiene caracteres no válidos (números o símbolos)."
            FinSi
        FinSi
        // Se repite si el nombre está vacío O si contiene caracteres inválidos
    Hasta Que nombreSoloLetras Y LongitudNombre > 0
    
    Limpiar Pantalla
    
    // ==========================================
    // 2. BUCLE PRINCIPAL DEL PEDIDO
    // ==========================================
    Mientras Mayusculas(continuar) = "S" Hacer
        
        // --- SELECCIÓN DE CATEGORÍA ---
        Repetir
            Escribir "Hola ", nombreUsuario, ", ¿qué desea ordenar?"
            Escribir "1. Platos (Pollos, Hamburguesas, Alitas, Papas)"
            Escribir "2. Bebidas (Jugos, Gaseosas, Café)"
            Escribir "--------------------------------"
            Leer opcionCategoria
            
            categoriaValida <- (opcionCategoria = 1 O opcionCategoria = 2)
            Si NO categoriaValida Entonces
                Escribir ">>> Error: Elija 1 o 2."
            FinSi
        Hasta Que categoriaValida
        
        Limpiar Pantalla
        productoValido <- Falso
        
        // --- SELECCIÓN DEL REPERTORIO ---
        Repetir
            Segun opcionCategoria Hacer
                1: // Categoria PLATOS
                    Escribir "--- MENÚ TASTY HOT CHICKEN: PLATOS ---"
                    Escribir "1. Brosther Pecho (S/ 12)"
                    Escribir "2. Brosther Entre-Pierna (S/ 11)"
                    Escribir "3. Brosther Pierna (S/ 10)"
                    Escribir "4. Brosther Ala (S/ 9)"
                    Escribir "5. Salchibrosther (S/ 16)"
                    Escribir "6. Hamburguesa clásica (S/ 8)"
                    Escribir "7. Hamburguesa mixta (S/ 10)"
                    Escribir "8. Hamburguesa Royal (S/ 12)"
                    Escribir "9. Hamburguesa Tasty (S/ 22)"
                    Escribir "10. Alitas bbq (S/ 20)"
                    Escribir "11. Alitas Acevichadas (S/ 20)"
                    Escribir "12. Alitas Crispy (S/ 20)"
                    Escribir "13. Alitas Maracuya (S/ 20)"
                    Escribir "14. Alitas picantes (S/ 20)"
                    Escribir "15. Salchipapa clásica (S/ 8)"
                    Escribir "16. Salchipapa espacial (S/ 11)"
                    Escribir "17. Salchipapa amazónica (S/ 25)"
                    Escribir "18. Choripapa clásica (S/ 10)"
                    Escribir "19. Choripapa especial (S/ 13)"
                    Escribir "------------------------------"
                    Escribir "Seleccione el número del plato:"
                    Leer opcionProducto
                    
                    // ASIGNACIÓN DE PRECIOS PLATOS
                    Segun opcionProducto Hacer
                        1: nombreProductoActual<-"Brosther Pecho"; precioUnitarioActual<-12; productoValido<-Verdadero;
                        2: nombreProductoActual<-"Brosther E-Pierna"; precioUnitarioActual<-11; productoValido<-Verdadero;
                        3: nombreProductoActual<-"Brosther Pierna"; precioUnitarioActual<-10; productoValido<-Verdadero;
                        4: nombreProductoActual<-"Brosther Ala"; precioUnitarioActual<-9; productoValido<-Verdadero;
                        5: nombreProductoActual<-"Salchibrosther"; precioUnitarioActual<-16; productoValido<-Verdadero;
                        6: nombreProductoActual<-"Hamburg. Clásica"; precioUnitarioActual<-8; productoValido<-Verdadero;
                        7: nombreProductoActual<-"Hamburg. Mixta"; precioUnitarioActual<-10; productoValido<-Verdadero;
                        8: nombreProductoActual<-"Hamburg. Royal"; precioUnitarioActual<-12; productoValido<-Verdadero;
                        9: nombreProductoActual<-"Hamburg. Tasty"; precioUnitarioActual<-22; productoValido<-Verdadero;
                        10: nombreProductoActual<-"Alitas BBQ"; precioUnitarioActual<-20; productoValido<-Verdadero;
                        11: nombreProductoActual<-"Alitas Acevichadas"; precioUnitarioActual<-20; productoValido<-Verdadero;
                        12: nombreProductoActual<-"Alitas Crispy"; precioUnitarioActual<-20; productoValido<-Verdadero;
                        13: nombreProductoActual<-"Alitas Maracuyá"; precioUnitarioActual<-20; productoValido<-Verdadero;
                        14: nombreProductoActual<-"Alitas Picantes"; precioUnitarioActual<-20; productoValido<-Verdadero;
                        15: nombreProductoActual<-"Salchipapa Clásica"; precioUnitarioActual<-8; productoValido<-Verdadero;
                        16: nombreProductoActual<-"Salchipapa Espacial"; precioUnitarioActual<-11; productoValido<-Verdadero;
                        17: nombreProductoActual<-"Salchipapa Amazónica"; precioUnitarioActual<-25; productoValido<-Verdadero;
                        18: nombreProductoActual<-"Choripapa Clásica"; precioUnitarioActual<-10; productoValido<-Verdadero;
                        19: nombreProductoActual<-"Choripapa Especial"; precioUnitarioActual<-13; productoValido<-Verdadero;
                        De Otro Modo:
							Escribir ">>> Error: Opción de plato no válida."
							productoValido <- Falso
                    FinSegun
                    
                2: // Categoria BEBIDAS
                    Escribir "--- MENÚ TASTY HOT CHICKEN: BEBIDAS ---"
                    Escribir "1. Bebida de Cocona (S/ 2)"
                    Escribir "2. Bebida de Chicha Morada (S/ 2)"
                    Escribir "3. Gaseosa Personal (S/ 4)"
                    Escribir "4. Agua personal (S/ 2)"
                    Escribir "5. Café (S/ 3)"
                    Escribir "6. Jugo de Fresa (S/ 4)"
                    Escribir "7. Jugo de Plátano (S/ 4)"
                    Escribir "8. Jugo Especial (S/ 6)"
                    Escribir "9. Jugo de Piña (S/ 4)"
                    Escribir "10. Jugo de Malta (S/ 7)"
                    Escribir "------------------------------"
                    Escribir "Seleccione el número de la bebida:"
                    Leer opcionProducto
                    
                    // ASIGNACIÓN DE PRECIOS BEBIDAS
                    Segun opcionProducto Hacer
                        1: nombreProductoActual<-"Bebida Cocona"; precioUnitarioActual<-2; productoValido<-Verdadero;
                        2: nombreProductoActual<-"Chicha Morada"; precioUnitarioActual<-2; productoValido<-Verdadero;
                        3: nombreProductoActual<-"Gaseosa Personal"; precioUnitarioActual<-4; productoValido<-Verdadero;
                        4: nombreProductoActual<-"Agua Personal"; precioUnitarioActual<-2; productoValido<-Verdadero;
                        5: nombreProductoActual<-"Café"; precioUnitarioActual<-3; productoValido<-Verdadero;
                        6: nombreProductoActual<-"Jugo Fresa"; precioUnitarioActual<-4; productoValido<-Verdadero;
                        7: nombreProductoActual<-"Jugo Plátano"; precioUnitarioActual<-4; productoValido<-Verdadero;
                        8: nombreProductoActual<-"Jugo Especial"; precioUnitarioActual<-6; productoValido<-Verdadero;
                        9: nombreProductoActual<-"Jugo Piña"; precioUnitarioActual<-4; productoValido<-Verdadero;
                        10: nombreProductoActual<-"Jugo Malta"; precioUnitarioActual<-7; productoValido<-Verdadero;
                        De Otro Modo:
                            Escribir ">>> Error: Opción de bebida no válida."
                            productoValido <- Falso
                    FinSegun
            FinSegun
        Hasta Que productoValido
        
        // --- INGRESO DE CANTIDAD ---
        Repetir
            Escribir "Ha seleccionado: ", nombreProductoActual
            Escribir "¿Cuántas unidades desea? (Mayor a 0):"
            Leer cantidadActual
            Si cantidadActual <= 0 Entonces
				Escribir ">>> Error: Cantidad inválida."
            FinSi
        Hasta Que cantidadActual > 0
        
        // --- CÁLCULOS Y GUARDADO EN ARREGLOS ---
        subtotalLinea <- precioUnitarioActual * cantidadActual
        totalGeneral <- totalGeneral + subtotalLinea
        
        contadorItems <- contadorItems + 1
        listaNombres[contadorItems] <- nombreProductoActual
        listaCantidades[contadorItems] <- cantidadActual
        listaSubtotales[contadorItems] <- subtotalLinea
        
        Escribir ">> Agregado. Subtotal parcial: S/ ", subtotalLinea
        
        // --- PREGUNTA PARA CONTINUAR ---
        Escribir ""
        Escribir "¿Desea agregar otro producto? (S/N)"
        Leer continuar
        Limpiar Pantalla
    Fin Mientras
    
    // ==========================================
    // 3. RESUMEN FINAL DETALLADO
    // ==========================================
    Limpiar Pantalla
    Escribir "========================================"
    Escribir "   RESUMEN DEL PEDIDO - TASTY HOT CHICKEN"
    Escribir "========================================"
    Escribir "Cliente: ", nombreUsuario
    Escribir "----------------------------------------"
    Escribir "Cant. | Descripción          | Total Ítem"
    Escribir "----------------------------------------"
    
    Para i <- 1 Hasta contadorItems Con Paso 1 Hacer
        // Usamos "Sin Saltar" para que quede en una sola línea
        Escribir "[", listaCantidades[i], "]   | " Sin Saltar
        Escribir listaNombres[i], " | S/ ", listaSubtotales[i]
    Fin Para
    
    Escribir "========================================"
    Escribir "TOTAL A PAGAR: S/ ", totalGeneral
    Escribir "========================================"
    Escribir "¡Gracias por su compra en Tasty Hot Chicken!"
FinAlgoritmo