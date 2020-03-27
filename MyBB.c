#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>
char op[10];
char singleLine[50];
char palavra1[5];
char palavra2[5];
char palavra3[5];
char palavra4[5];
char palavra5[5];
char binary[10];
char d[15];
int i,y,a,no;
char hex[5];
char teste[] = "0";
int typeop = 0;
int decimal_binary(int n);

//type 1 = r
//type 2 = i
//type 3 = j
void opcode(char teste[], int type){


    if (strcmp(teste,"end\n") == 0){
        strcpy(teste,"");
        type = 999;
    }

    if (strcmp(teste,"end") == 0){
        strcpy(teste,"");
        type = 999;
    }


    if (strcmp(teste,"add") == 0){
        strcpy(teste,"100000");
        type = 1;



    }
    if (strcmp(teste,"sub") == 0){
        strcpy(teste,"100010");
       type = 1;
    }
    if (strcmp(teste,"mult") == 0){
        strcpy(teste,"011000");
         type = 1;
    }
    if (strcmp(teste,"div") == 0){
        strcpy(teste,"011010");
        type = 1;
    }
    if (strcmp(teste,"xor") == 0){
        strcpy(teste,"100110");
        type = 1;
    }
    if (strcmp(teste,"nor") == 0){
        strcpy(teste,"100111");
         type = 1;
    }
    if (strcmp(teste,"slt") == 0){
        strcpy(teste,"101010");
         type = 1;
    }
    if (strcmp(teste,"and") == 0){
        strcpy(teste,"100100");
        type = 1;
    }
    if (strcmp(teste,"sll") == 0){
        strcpy(teste,"000000");
         type = 4;
    }
    if (strcmp(teste,"srl") == 0){
        strcpy(teste,"000010");
          type = 1;
    }
    if (strcmp(teste,"jr") == 0){
        strcpy(teste,"001000");
           type = 1;
    }
    if (strcmp(teste,"or") == 0){
        strcpy(teste,"100101");
        type = 1;
    }
    if (strcmp(teste,"j") == 0){
        strcpy(teste,"000010");
        type = 3;
    }
    if (strcmp(teste,"jal") == 0){
        strcpy(teste,"000011");
          type = 3;
    }
    if (strcmp(teste,"addi") == 0){
        strcpy(teste,"001000");
        type = 2;
    }
    if (strcmp(teste,"lw") == 0){
        strcpy(teste,"100011");
          type = 5;
    }
    if (strcmp(teste,"sw") == 0){
        strcpy(teste,"101011");
       type = 5;
    }
    if (strcmp(teste,"beq") == 0){
        strcpy(teste,"000100");
        type = 2;
    }
    if (strcmp(teste,"bne") == 0){
        strcpy(teste,"000101");
         type = 2;
    }
    if (strcmp(teste,"slti") == 0){
        strcpy(teste,"001010");
        type = 2;
    }
    if (strcmp(teste,"andi") == 0){
        strcpy(teste,"001100");
      type = 2;
    }
    if (strcmp(teste,"ori") == 0){
        strcpy(teste,"001101");
        type = 2;
    }


typeop = type;

}



void regcode(char* reg){

     if (strcmp(reg,"zero") == 0)
        strcpy(reg,"0");
     else if (strcmp(reg,"at") == 0)
        strcpy(reg,"1");

     else if (strcmp(reg,"v0") == 0)
        strcpy(reg,"10");

     else if (strcmp(reg,"v1") == 0)
        strcpy(reg,"11");

    else  if (strcmp(reg,"a0") == 0)
        strcpy(reg,"100");

    else if (strcmp(reg,"a1") == 0)
        strcpy(reg,"101");

    else if (strcmp(reg,"a2") == 0)
        strcpy(reg,"110");

    else if (strcmp(reg,"a3") == 0)
        strcpy(reg,"111");

    else if (strcmp(reg,"t0") == 0)
        strcpy(reg,"1000");

    else if (strcmp(reg,"t1") == 0)
        strcpy(reg,"1001");

    else if (strcmp(reg,"t2") == 0)
        strcpy(reg,"1010");

    else if (strcmp(reg,"t3") == 0)
        strcpy(reg,"1011");

    else if (strcmp(reg,"t4") == 0)
        strcpy(reg,"1100");

    else if (strcmp(reg,"t5") == 0)
        strcpy(reg,"1101");

    else if (strcmp(reg,"t6") == 0)
        strcpy(reg,"1110");

    else if (strcmp(reg,"t7") == 0)
        strcpy(reg,"1111");

    else if (strcmp(reg,"s0") == 0)
        strcpy(reg,"10000");

    else if (strcmp(reg,"s1") == 0)
        strcpy(reg,"10001");

    else if (strcmp(reg,"s2") == 0)
        strcpy(reg,"10010");

    else if (strcmp(reg,"s3") == 0)
        strcpy(reg,"10011");

    else if (strcmp(reg,"s4") == 0)
        strcpy(reg,"10100");

    else if (strcmp(reg,"s5") == 0)
        strcpy(reg,"10101");

    else if (strcmp(reg,"s6") == 0)
        strcpy(reg,"10110");

    else if (strcmp(reg,"s7") == 0)
        strcpy(reg,"10111");

    else if (strcmp(reg,"t8") == 0)
        strcpy(reg,"11000");

    else if (strcmp(reg,"s9") == 0)
        strcpy(reg,"11001");

    else if (strcmp(reg,"k0") == 0)
        strcpy(reg,"11010");

    else if (strcmp(reg,"k1") == 0)
        strcpy(reg,"11011");

    else if (strcmp(reg,"gp") == 0)
        strcpy(reg,"11100");

    else if (strcmp(reg,"sp") == 0)
        strcpy(reg,"11101");

    else if (strcmp(reg,"fp") == 0)
        strcpy(reg,"11110");

    else if (strcmp(reg,"ra") == 0)
        strcpy(reg,"11111");

    else {



            if (typeop == 3){

                no = atoi(reg);
                if(no >= 1024){
                    strcpy(reg,"10000000000");
                }else{


                no = decimal_binary(no);
                sprintf(d, "%d", no);
                strcpy(reg,d);
                }


            }else{
              no = atoi(reg);
              no = decimal_binary(no);
              sprintf(d, "%d", no);
              numtobin(d);
              strcpy(reg,d);
            }












        }

}




int decode()
{

 setlocale(LC_ALL, "Portuguese");
 fflush(stdin);
 FILE * fPointer = fopen("Entrada.txt", "r");
 FILE* outfile = fopen("Saida.txt", "w");


 while (!feof(fPointer)){

    fgets(singleLine, 150, fPointer);
    char * pch;
    //printf("Lendo instruções MIPS \"%s\"\n",singleLine);
    pch = strtok (singleLine," ,.()- ");
    i=0;
    while (pch != NULL)
    {

        if (i == 0) {

           strcpy(palavra1,pch);


        }
        if (i == 1){

            strcpy(palavra2,pch);
        }
        if (i == 2) {
            strcpy(palavra3,pch);
        }
        if (i == 3){
            strcpy(palavra4,pch);

        }
        if (i == 4){
            strcpy(palavra5,pch);
        }

        pch = strtok (NULL, " ,.-");
        i++;



    }


 opcode(palavra1,typeop);
  regcode(palavra2);
 regcode(palavra3);
 regcode(palavra4);


 if (strcmp(palavra4,"") == 0){
    strcpy(palavra4,"00000");
 }



 // type r
 if (typeop == 1) {

        //caso de 4 comandos
       if (i == 4) {





        //printf("\nTypo R: %s, %s, %s, %s",palavra1,palavra2,palavra3,palavra4);
        //printf("\nMachine code: (000000)(%s)(%s)(%s)(00000)(%s)",palavra3,palavra2,palavra4,palavra1);
        printf("000000%s%s%s00000%s",palavra3,palavra4,palavra2,palavra1);
        fprintf(outfile,"000000%s%s%s00000%s",palavra3,palavra4,palavra2,palavra1);
        fprintf(outfile,"\n");

printf("\n Palavra1 = %s",palavra1);



        // caso de 3 comandos
       } else if (i == 3){

       //printf("\nTypo R: %s, %s, %s, %s",palavra1,palavra2,palavra3,palavra4);
        //printf("\nMachine code: (000000)(%s)(%s)(%s)(00000)(%s)",palavra2,palavra3,palavra4,palavra1);
        printf("000000%s%s%s00000%s",palavra2,palavra3,palavra4,palavra1);
        fprintf(outfile,"000000%s%s%s00000%s",palavra2,palavra3,palavra4,palavra1);
        fprintf(outfile,"\n");

       //caso de 2 comandos
       } else if (i == 2){
        //printf("\nTypo R: %s, %s,",palavra1,palavra2);
        //printf("\nMachine code: (000000)(%s)(00000)(00000)(00000)(%s)",palavra2,palavra1);
        printf("000000%s000000000000000%s",palavra2,palavra1);
        fprintf(outfile,"000000%s000000000000000%s",palavra2,palavra1);
        fprintf(outfile,"\n");

       }


 }

 //type i ; I opcode rs rt immediate
 if (typeop == 2) {


  //I opcode rs rt immediate



     //printf("\nTypo I: %s, %s, %s, %s",palavra1,palavra2,palavra3,palavra4);
    // printf("\nMachine Code: %s%s%s00000000000%s",palavra1,palavra3,palavra2,palavra4);
   printf("%s%s%s00000000000%s",palavra1,palavra3,palavra2,palavra4);
   fprintf(outfile,"%s%s%s00000000000%s",palavra1,palavra3,palavra2,palavra4);
    fprintf(outfile,"\n");

 }

 if (typeop == 3) {

     //printf("\nTypo j: %s, %s",palavra1,palavra2);
     //printf("\nMachine code: (%s)(00000000000000)(%s)",palavra1,palavra2);
     if (strlen(palavra2) == 11) {
       printf("%s00000000000000%s",palavra1,palavra2);
      fprintf(outfile,"%s00000000000000%s",palavra1,palavra2);
     }

     if (strlen(palavra2) == 10) {
       printf("%s000000000000000%s",palavra1,palavra2);
      fprintf(outfile,"%s000000000000000%s",palavra1,palavra2);
     }

     if (strlen(palavra2) == 9) {
       printf("%s0000000000000000%s",palavra1,palavra2);
      fprintf(outfile,"%s000000000000000%s",palavra1,palavra2);
     }

     fprintf(outfile,"\n");

 }

 if (typeop == 4){


                        // printf("\nTypo R: %s, %s, %s, %s",palavra1,palavra2,palavra3,palavra4);
                        //printf("\nMachine code: (000000)(%s)(%s)(%s)(00000)(%s)",palavra3,palavra2,palavra4,palavra1);
                        printf("00000000000%s%s%s%s",palavra3,palavra4,palavra2,palavra1);
                        fprintf(outfile,"00000000000%s%s%s%s",palavra3,palavra4,palavra2,palavra1);
                        fprintf(outfile,"\n");


       }


    if (typeop == 5) {


  //I opcode rs rt immediate



     //printf("\nTypo I: %s, %s, %s, %s",palavra1,palavra2,palavra3,palavra4);
     //printf("\nMachine Code: %s%s000000000000000%s",palavra1,palavra1,palavra3);
    fprintf(outfile,"%s%s000000000000000%s",palavra1,palavra1,palavra3);
    printf("%s%s000000000000000%s",palavra1,palavra1,palavra3);
    fprintf(outfile,"\n");

 }

  if (typeop == 999){


    break;



  }




   printf("\n");


 }

 fclose(fPointer);
 fclose(outfile);
   return 0;
}


void numtobin(char* decimal){





int a = strlen(decimal);

    if (a >= 5)
     strcpy(binary,"");
    else if (a == 4)
     strcpy(binary,"0");
    else if (a == 3)
     strcpy(binary,"00");
    else if (a == 2)
     strcpy(binary,"000");
    else if (a <= 1)
     strcpy(binary,"0000");
    strcat(binary,decimal);
    strcpy(decimal,binary);






}

int decimal_binary(int n)
{
    if (n==0)
        return 0;
    else
        return ((n%2)+10*decimal_binary(n/2));
}

