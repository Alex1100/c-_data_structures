/**************************************
 * @class AdjacencyList
 * @desc  Implements AdjacencyList
 *************************************/

// still need to add dynamic memory allocation

template <class T>
void AdjacencyList<T>::add_vertex(T vertex) {
  bool vertexExists = has_vertex(vertex);

  if (!vertexExists) {
    node_list[rear] = vertex;
    rear++;
    adjacency_list->insert(vertex, vertex);
  }
}

template <class T>
bool AdjacencyList<T>::has_vertex(T vertex) {
  bool found = adjacency_list->contains(vertex);
  for (int i = 0; i < rear; i++) {
    if (node_list[i] == vertex && found) {
      return true;
    }
  }

  return false;
}
