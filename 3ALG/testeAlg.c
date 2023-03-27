#include <stdio.h>
#include <stdlib.h>


//operação elementar de Permuta da i-ésima e j-ésima linha (Li <--> Lj );
void op1(int tamL, int tamC, float mat[tamL][tamC], int li, int lj){
    int temp;
    int i;
    for (i = 0; i < tamC; i++){
        //guardo o conteúdo que será subistituido numa var
        temp = mat[li][i];
        //substituo pelo elemento da outra linha
        mat[li][i] = mat[lj][i];
        //por fim resgato o elemento na var e coloco na l2
        mat[lj][i]=temp;
    }

}
//Multiplicação da i-ésima linha por um escalar não nulo k(Li -> kLi );
void op2(int tamL, int tamC, float mat[tamL][tamC], int li, float k){
    int i;
    for(i = 0; i<tamC;i++){
        mat[li][i] = mat[li][i] * k;
    }
}

//Substituição da i-ésima linha por uma combinação linear desta com uma outra linha da matriz (Li -> aLi + bLj );
void op3(int tamL, int tamC, float mat[tamL][tamC], int li, int lj, int a, int b){
    int i,j;
    for(i=0;i<tamC;i++){
        mat[li][i] = (a * mat[li][i]) + (b * mat[lj][i]);
    }
}

void exibirMat(int tamL, int tamC, float mat[tamL][tamC]){
    int i;
    int j;
    for(i=0; i< tamL;i++){
        for(j=0; j< tamC;j++){
            printf("%.2f ", mat[i][j]);
        }
        printf("\n\n");
        
    }
    printf("\n");
}

int alg(int tamL, int tamC, float mat[tamL][tamC]){
    int i,j,aux;

    for(i=0,j=0; i< tamL;i++,j++){
        /*if (mat[i][j] == 0){
        
        }*/
        aux = i;
        while (mat[i][j] == 0){
            printf("\n entrei no while");
            op1(tamL,tamC,mat,i, aux + 1);
            aux++;
        }
        //já não é mais 0

        //agora para evitar if dividimos a linha pelo numero do pivô para garantir o numero 1
        op2(3,4,mat,i,(1.0/mat[i][j]));
        printf("\nagora para evitar if dividimos a linha pelo numero do pivô para garantir o numero 1\n\n");
        exibirMat(tamL,tamC,mat);
        //pivô é 1

        //zerar quem está em cima e embaixo do pivô
        //em cima:
        for(aux = i -1;aux>=0;aux--){
            op3(tamL,tamC,mat,aux,i,1,(-1 * mat[aux][j]));
        }
        printf("\n zerei quem está em cima do pivô\n\n");
        exibirMat(tamL,tamC,mat);

        //embaixo
        for (aux = i + 1;aux < tamL;aux++)
        {
            op3(tamL,tamC,mat,aux,i,1,(-1 * mat[aux][j]));
        }
        printf("\nagora quem está em baixo \n\n");
        exibirMat(tamL,tamC,mat);
        //pivotiei a coluna

        //hora de descer uma linha e andar uma casa
    }   

    return 0;
}

int main()
{
    float mat[2][2] = {{1,2}, {3,4}};
    //exibirMat(2,2,mat);

    float mat2[2][4] ={{1,3,2,5}, {2,1,-1,0}};
    //exibirMat(2,4,mat2);

    float matTest[3][4] = {{1,3,2,5}, {2,1,-1,0}, {0,2,-4,-2}};
    exibirMat(3,4,matTest);

    alg(3,4,matTest);

    //op1(2,2,mat,0,1);
    //exibirMat(2,2,mat);

    //op2(2,2,mat,1,(1.0/mat[1][1]));
    //exibirMat(2,2,mat);

    //op3(2,4,mat2,1,0,1,-2);
    //exibirMat(2,4,mat2);


    return 0;
}
