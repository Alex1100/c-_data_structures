/**************************************
 * @class AdjacencyList
 * @desc  Implements AdjacencyList
 *************************************/

// still need to add dynamic memory allocation

template <class T, class U>
void AdjacencyList<T, U>::add_vertex(T vertex, U weight, U heuristic) {
  bool vertex_exists = has_vertex(vertex);

  if (!vertex_exists) {
    node_list[rear] = vertex;
    rear++;
    adjacency_list->insert(vertex, vertex, weight, heuristic);
  }
}

template <class T, class U>
bool AdjacencyList<T, U>::has_vertex(T vertex) {
  bool found = adjacency_list->contains(vertex);
  for (int i = 0; i < rear; i++) {
    if (node_list[i] == vertex && found) {
      return true;
    }
  }

  return false;
}

template <class T, class U>
void AdjacencyList<T, U>::add_edges(T from, T to) {
  auto from_found = adjacency_list->contains(from);
  auto to_found = adjacency_list->contains(to);

  if (!from_found || !to_found) {
    throw runtime_error("One or more Vertexes not found in the graph.");
  }

  node<T, T, U> *from_node = adjacency_list->get_entry(from);
  node<T, T, U> *to_node = adjacency_list->get_entry(to);

  adjacency_list->get_storage()[adjacency_list->hash(to)].add_node(
    from,
    from,
    from_node->data.weight,
    from_node->data.heuristic
  );

  adjacency_list->get_storage()[adjacency_list->hash(from)].add_node(
    to,
    to,
    to_node->data.weight,
    to_node->data.heuristic
  );
}

template <class T, class U>
void AdjacencyList<T, U>::add_edge(T from, T to) {
  auto from_found = adjacency_list->contains(from);
  auto to_found = adjacency_list->contains(to);

  if (!from_found || !to_found) {
    throw runtime_error("One or more Vertexes not found in the graph.");
  }

  node<T, T, U> *to_node = adjacency_list->get_entry(to);

  adjacency_list->get_storage()[adjacency_list->hash(from)].add_node(
    to,
    to,
    to_node->data.weight,
    to_node->data.heuristic
  );
}
