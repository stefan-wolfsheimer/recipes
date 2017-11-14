#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "n_queens.h"

int parse_size(const char ** argv, int i, int argc, size_t * s)
{
  if( (i+1) < argc) 
  {
    char * pend;
    long int tmp = strtol(argv[i+1], &pend, 10);
    if(*pend || tmp < 0) 
    {
      return 1;
    }
    else 
    {
      *s = tmp;
      return 0;
    }
  }
  return 1;
}

int main(int argc, const char ** argv)
{
  int           i;
  int           verbose = 0;
  size_t        n_queens = 8;
  size_t        board_size = 8;
  int           err = 0;
  int           help = 0;
  chess_board_t board;
  for(i = 1; i < argc; i++) 
  {
    if(!strcmp("--verbose", argv[i]) || 
       !strcmp("-v", argv[i]))
    {
      verbose = 1;
    }
    else if(!strcmp("-n", argv[i]) || 
            !strcmp("-n-queens", argv[i]))
    {
      if(parse_size(argv, i, argc, &n_queens)) err = 1;
      else i++;
    }
    else if(!strcmp("-s", argv[i]) || 
            !strcmp("--size", argv[i]))
    {
      if(parse_size(argv, i, argc, &board_size)) err = 1;
      else i++;
    }
    else if(!strcmp("-h", argv[i]) || 
            !strcmp("--help", argv[i])) 
    {
      help = 1;
    }
    else 
    {
      err = 1;
    }
  }
  if(err) 
  {
    help = 1;
  }
  if(help) 
  {
    printf("usage: %s [OPTIONS]\n",argv[0]);
    printf("OPTIONS:\n");
    printf("--verbose,-v    print all solutions\n");
    printf("--size,-s       size of the chess board (default 8)\n");
    printf("--n-queens,-n   number of queens (default 8)\n");
    if(err) 
    {
      return 8;
    }
    else 
    {
      return 0;
    }
  }
  init_board(&board, board_size);
  board.verbose = verbose;
  solve_n_queens_problem(stdout, &board, n_queens);
  print_n_queens_summary(stdout, &board);
  free_board(&board);
  return 0;
}
