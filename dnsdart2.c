/*
+=======================+
+CODIGO FEITO POR SOLDAT+
+=======================+
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h> //biblioteca de familia de protocolo de internet
#include <arpa/inet.h> //biblioteca operações de internet
#include <netdb.h> //biblioteca para operações de redes
#include <string.h> //para manipuar strings


int main(int argc, char *argv[]) {

    char *alvo;
    alvo = argv[1];
    struct hostent *host;

    char txt[100];
    char *resultado;

    FILE *dart;
    dart = fopen(argv[2], "r");
    
	if (argv[1] == NULL)
	{
	  //menu inicial
	  printf(R"EOF(

 #####  #    #  ####     #####    ##   #####  ##### 
 #    # ##   # #         #    #  #  #  #    #   #   
 #    # # #  #  ####     #    # #    # #    #   #   
 #    # #  # #      #    #    # ###### #####    #   
 #    # #   ## #    #    #    # #    # #   #    #   
 #####  #    #  ####     #####  #    # #    #   #
 
 Modo de uso ./dnsdart alvo.com dart.txt

 )EOF");
	  return 0;
}
	while(fscanf(dart, "%s", &txt) != EOF) {
          resultado = (char *) strcat(txt, alvo); //juntando os dois arquivos
          host = gethostbyname(resultado);
          if (host == NULL)
          {
          	continue;
          }
          printf("HOST ENCONTRADO ===> %s IP ====> %s\n", resultado, inet_ntoa(*((struct in_addr *)host->h_addr)));
	}

}
