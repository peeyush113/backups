;; -*- scheme -*-


(define (format-cdfggen-kind name)
  (upcase (concat-strings (syllables name) "_")))

(chunk cdfggen
  (struct-fmt "~a")
  (pointer-fmt "p~a")
  (kind-fmt-func format-cdfggen-kind)
  (creator-fmt "m~a"))

(header-add "#include <freehdl/tree-supp.h>"
	    "#include <string>"
	    "#include <vector>"
	    "typedef enum {to, downto} cdfgg_direction;"
	    "using namespace std;")

(impl-add "#include <freehdl/cdfggen-chunk.h>")

(defctype int) 
(defctype double) 
(defctype string)
(defctype cdfgg_direction) 
(defctype cdfgg_char_p (cname "char*"))
(defctype lint (cname "long long int"))
(defctype vector_pair_string_lint (cname "vector<pair<string, long long int> >"))
(defctype vector_int (cname "vector<int>"))


;; ******************************************************************
;; VHDL types
;; ******************************************************************

(defnode CDFGG_Type ()
  (
   (string instance_name)
   (string type_name)
   (CDFGG_Type base_type)
   ))


(defnode CDFGG_ScalarType (CDFGG_Type)
  ())

(defnode CDFGG_IntegerType (CDFGG_ScalarType)
  (
   (int left_bound)
   (cdfgg_direction direction)
   (int right_bound)
   ))

(defnode CDFGG_RealType (CDFGG_ScalarType)
  (
   (double left_bound)
   (cdfgg_direction direction)
   (double right_bound)
   ))

(defnode CDFGG_EnumerationType (CDFGG_ScalarType)
  (
   (int left_bound)
   (int right_bound)
   ))

(defnode CDFGG_PhysicalType (CDFGG_ScalarType)
  (
   (lint left_bound)
   (cdfgg_direction direction)
   (lint right_bound)
   (vector_pair_string_lint units)
   ))


(defnode CDFGG_CompositeType (CDFGG_Type)
  ())

(defnode CDFGG_ArrayType (CDFGG_CompositeType)
  (
   (lint left_bound)
   (cdfgg_direction direction)
   (lint right_bound)
   (CDFGG_Type index_type)
   (CDFGG_Type element_type)
   ))



;; ******************************************************************
;; Edge 
;; ******************************************************************

(defnode CDFGG_Edge ()
  (
   (int index)
   (int in_node)
   (int out_node)
   (CDFGG_Type type)
   ))


(defnode CDFGG_DataEdge (CDFGG_Edge)
  ())

(defnode CDFGG_LiteralEdge (CDFGG_Edge)
  ())

(defnode CDFGG_StringLiteralEdge (CDFGG_LiteralEdge)
  (
   (cdfgg_char_p edge_name)
   ))

(defnode CDFGG_IntegerLiteralEdge (CDFGG_LiteralEdge)
  (
   (int value)
   ))

(defnode CDFGG_RealLiteralEdge (CDFGG_LiteralEdge)
  (
   (double value)
   ))

(defnode CDFGG_RangeLiteralEdge (CDFGG_LiteralEdge)
  (
   (int left_bound)
   (cdfgg_direction direction)
   (int right_bound)
   ))



;; ******************************************************************
;; Node
;; ******************************************************************

(defnode CDFGG_Node ()
  (
   (int index)
   (string type)
   (vector_int incoming_edges)
   (vector_int outgoing_edges)
   ))

