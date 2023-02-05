# API Graph Ranker

## About 

Final project for the course "Algoritmi e Principi dell'Informatica" at Politecnico di Milano (2020/2021).

Final score: 30L/30

## Programming Languages 

![C](https://img.shields.io/badge/C-%20-black)

## Professor
Davide Martinenghi

## Specifications

The aim of the project is to efficiently realise a classifier of graphs in terms of both time and space complexity: a ranking of direct and weighted graphs needs to be managed, taking into account the k best graphs.

It is possible to use the programme via the STDIN: the commands AddGraph is used to add a graph to the ranking and TopK to show the k best graphs possible. The number of graphs and k are always specified via the STDIN.

The ranking metric is defined by the sum of all minimum paths between node 0 and all other nodes in the graph that can be reached from 0.
