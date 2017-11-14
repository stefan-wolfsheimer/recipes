#include <stdlib.h>
#include <stdio.h>
#ifndef __N_QUEENS_H__
#define __N_QUEENS_H__

/** 
 * Chess board for solving the n-queens problem
 */
typedef struct chess_board_t 
{
  size_t      L;           /* side length of the board */
  size_t      L2;          /* number of fields */
  short int * h_line;      /* indicator: horizontal line reachable 
                              h_line[0] ... h_line[L-1]
                            */
  short int * v_line;      /* indicator: vertical line reachable 
                              v_line[0] ... h_line[L-1]
                            */
  short int * d_p_line;    /* indicator: diagonal line reachable 
                              d_p_line[0] ... h_line[2*L-2]
                            */ 
  short int * d_m_line;    /* indicator: diagonal line rachable 
                              d_m_line[-L+1] ... h_line[L-1]
                            */
  short int * queens;      /* indicator: field is occupied 
                              queens[0] ... queens[L2]
                            */
  size_t      n_solutions; /* solution counter */

  size_t      multipl[9];  /* statistics of multiplicities of solutions */

  int         verbose;
} chess_board_t;

/***********************************************************
 * Initialize workspace for n-queens computation 
 * @param board to be initialized 
 * @param L side length of the board
 ***********************************************************/
void init_board(chess_board_t * board, size_t L);

/***********************************************************
 * Free allocated memory for chess board 
 * @param board initialized with init_board
 ***********************************************************/
void free_board(chess_board_t * board);

/***********************************************************
 * Print board to file 
 * @param fp file descriptor 
 * @param board chess board to be written 
 ***********************************************************/
void print_board(FILE * fp, chess_board_t * board);

/***********************************************************
 * Print summary of n-queens problem:
 * number of solutions
 * number of fundamental solutions
 * multiplicities of solutions 
 ***********************************************************/
void print_n_queens_summary(FILE * fp, chess_board_t * board);

/***********************************************************
 * Solve the n queens problem and write the number of 
 * solutions to file.
 * If board->verbose is not 0, also write out all 
 * solutions.
 * @param fp file pointer 
 * @param board board initialized with init_board
 * @param n_queens number of queens to be placed on 
 *        the board
 ***********************************************************/
void solve_n_queens_problem(FILE          * fp,
                            chess_board_t * board,
                            size_t          n_queens);

#endif
