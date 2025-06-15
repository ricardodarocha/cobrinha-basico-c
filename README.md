# cobrinha-basico-c

```Javascript
//Considere um tabuleiro quadrado
//Modifique se quiser
int TAMANHO = 10; //O tamanho que voce quiser, 
(x, y) <-> i

// # Converta as coordenadas x, y em um índice i
//∀ x, y ∈ {0..TAMANHO-1}
i = y * TAMANHO + x;

// # Converta um índice i nas coordenadas (x, y)
//∀ i {0..TAMANHO²-1}
y = i / TAMANHO;
x = i % TAMANHO;
(x, y);
```
