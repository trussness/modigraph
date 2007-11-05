/* -*- mode: C -*-  */
/* 
   IGraph library.
   Copyright (C) 2006  Gabor Csardi <csardi@rmki.kfki.hu>
   MTA RMKI, Konkoly-Thege Miklos st. 29-33, Budapest 1121, Hungary
   
   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc.,  51 Franklin Street, Fifth Floor, Boston, MA 
   02110-1301 USA

*/

#include <igraph.h>

void print_vector(igraph_vector_t *v, FILE *f) {
  long int i;
  for (i=0; i<igraph_vector_size(v); i++) {
    fprintf(f, " %4.2f", VECTOR(*v)[i]);
  }
  fprintf(f, "\n");
}

int main() {

  igraph_t g;
  igraph_vector_t v, res;
  int ret;

  /* Test graphs taken from http://www.iprcom.com/papers/pagerank/ */
  igraph_vector_init(&v, 10);
  VECTOR(v)[0]=0; VECTOR(v)[1]=1;
  VECTOR(v)[2]=1; VECTOR(v)[3]=2;
  VECTOR(v)[4]=2; VECTOR(v)[5]=0;
  VECTOR(v)[6]=3; VECTOR(v)[7]=2;
  VECTOR(v)[8]=0; VECTOR(v)[9]=2;
  igraph_create(&g, &v, 0, 1);

  igraph_vector_init(&res, 0);
  igraph_pagerank_old(&g, &res, igraph_vss_all(), 1, 1000, 0.001, 0.85);
  print_vector(&res, stdout);
  igraph_vector_destroy(&res);
  igraph_vector_destroy(&v);
  
  igraph_destroy(&g);

  igraph_vector_init(&v, 28);
  VECTOR(v)[ 0]=0; VECTOR(v)[ 1]=1;
  VECTOR(v)[ 2]=0; VECTOR(v)[ 3]=2;
  VECTOR(v)[ 4]=0; VECTOR(v)[ 5]=3;
  VECTOR(v)[ 6]=1; VECTOR(v)[ 7]=0;
  VECTOR(v)[ 8]=2; VECTOR(v)[ 9]=0;
  VECTOR(v)[10]=3; VECTOR(v)[11]=0;
  VECTOR(v)[12]=3; VECTOR(v)[13]=4;
  VECTOR(v)[14]=3; VECTOR(v)[15]=5;
  VECTOR(v)[16]=3; VECTOR(v)[17]=6;
  VECTOR(v)[18]=3; VECTOR(v)[19]=7;
  VECTOR(v)[20]=4; VECTOR(v)[21]=0;
  VECTOR(v)[22]=5; VECTOR(v)[23]=0;
  VECTOR(v)[24]=6; VECTOR(v)[25]=0;
  VECTOR(v)[26]=7; VECTOR(v)[27]=0;
  igraph_create(&g, &v, 0, 1);

  igraph_vector_init(&res, 0);
  igraph_pagerank_old(&g, &res, igraph_vss_all(), 1, 1000, 0.001, 0.85);
  print_vector(&res, stdout);
  igraph_vector_destroy(&res);
  igraph_vector_destroy(&v);
  
  /* Errors */
  igraph_set_error_handler(igraph_error_handler_ignore);
  ret=igraph_pagerank_old(&g, &res, igraph_vss_all(), 1, -1, 0.001, 0.85);
  if (ret != IGRAPH_EINVAL) {
    return 1;
  }
  
  ret=igraph_pagerank_old(&g, &res, igraph_vss_all(), 1, 1000, -1, 0.85);
  if (ret != IGRAPH_EINVAL) {
    return 2;
  }
  
  ret=igraph_pagerank_old(&g, &res, igraph_vss_all(), 1, 1000, 0.001, 1.2);
  if (ret != IGRAPH_EINVAL) {
    return 3;
  }
  
  igraph_destroy(&g);
  return 0;
}
