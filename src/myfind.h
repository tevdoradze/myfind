#ifndef DEFINE_H
# define DEFINE_H

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

struct node
{
  char* name;
  char* name_wp; //name without path
  mode_t type; // link type (from lstat)
  mode_t r_type; // real rtype (from stat)
};


enum enum_type
{
  THEN = 0,
  AND,
  OR,
  NO,
  PRINT,
  CONDITION,
  EXEC,
  EXECP,
  PAO, //parentesis open
  PAC, //parentesis close
  FAPA // Factorized parentesis
};

struct compound
{
  char* name; //commande
  char **args; //commande args, NULL terminated
  struct compound ** fapa; // Used if et == FAPA
  enum enum_type et;
};

struct ast
{
  struct ast *left;
  struct ast *right;
  enum enum_type et;
  int rvalue[2]; // rvalue[0] contains return value of the left child, 1 right
  struct compound **c_list;
  size_t cl_size;
};

struct data
{
  int return_value;
  int d_checked;
  int option; // 0 -> P, 1 -> H, 2 -> L
  char **name_list;
  size_t nl_size;
  size_t nl_capacity;
  char **e_list; //expression list
  size_t el_size;
  size_t el_capacity;
  struct node **nodes;
  size_t no_size;
  size_t no_capacity;
  // Contains inodes of visited directories to avoid infinite loops
  int *inode_list;
  size_t il_size;
  size_t il_capacity;
  struct compound **c_list; //Factorized expressions before building ast
  size_t cl_size;
  size_t cl_capacity;
  struct ast *ast;
  int actions; // 1 if actions in ast (print, exec) ; 0 otherwise
};

#endif
