#include "kernel/types.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  int mask;

  if(argc < 3){
    fprintf(2, "uso: trace mask comando [args...]\n");
    exit(1);
  }

  mask = atoi(argv[1]);

  //Chamando trace  
  if(trace(mask) < 0){
    fprintf(2, "trace: erro ao ativar o trace\n");
    exit(1);
  }
  
  //Executando o comando
  exec(argv[2], &argv[2]);


  fprintf(2, "trace: exec %s falhou\n", argv[2]);
  exit(1);
}
