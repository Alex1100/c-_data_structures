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

  adjacency_list->get_storage()[adjacency_list->hash(from)].add_node(
    to,
    to,
    to_node->data.weight,
    to_node->data.heuristic
  );

  adjacency_list->get_storage()[adjacency_list->hash(to)].add_node(
    from,
    from,
    from_node->data.weight,
    from_node->data.heuristic
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

template <class T, class U>
void AdjacencyList<T, U>::remove_edges(T from, T to) {
  auto from_found = adjacency_list->contains(from);
  auto to_found = adjacency_list->contains(to);

  if (!from_found || !to_found) {
    throw runtime_error("One or more Vertexes not found in the graph.");
  }
  try {
    node<T, T, U> *removed_from_node = adjacency_list->get_storage()[adjacency_list->hash(from)].remove_node(to);
    node<T, T, U> *removed_to_node = adjacency_list->get_storage()[adjacency_list->hash(to)].remove_node(from);
  } catch (const runtime_error& err) {
    throw err;
  }
}

template <class T, class U>
void AdjacencyList<T, U>::remove_edge(T from, T to) {
  auto from_found = adjacency_list->contains(from);
  auto to_found = adjacency_list->contains(to);

  if (!from_found || !to_found) {
    throw runtime_error("One or more Vertexes not found in the graph.");
  }
  try {
    node<T, T, U> *removed_from_node = adjacency_list->get_storage()[adjacency_list->hash(from)].remove_node(to);
  } catch (const runtime_error& err) {
    throw err;
  }
}

template <class T, class U>
bool AdjacencyList<T, U>::has_edge(T from, T to) {
  auto from_found = adjacency_list->contains(from);
  auto to_found = adjacency_list->contains(to);

  if (!from_found || !to_found) {
    throw runtime_error("One or more Vertexes not found in the graph.");
  }

  return adjacency_list->get_storage()[adjacency_list->hash(from)].contains(to);
}

template <class T, class U>
bool AdjacencyList<T, U>::has_edges(T from, T to) {
  auto from_found = adjacency_list->contains(from);
  auto to_found = adjacency_list->contains(to);

  if (!from_found || !to_found) {
    throw runtime_error("One or more Vertexes not found in the graph.");
  }


  return (
    adjacency_list->get_storage()[adjacency_list->hash(to)].contains(from)
    && adjacency_list->get_storage()[adjacency_list->hash(from)].contains(to)
  );
}

template <class T, class U>
node<T, T, U> *AdjacencyList<T, U>::get_item(T key) {
  int src_index = adjacency_list->hash(key);
  node<T, T, U> *current_node = adjacency_list->get_storage()[src_index].get_item(key);
}

template <class T, class U>
void AdjacencyList<T, U>::dfs_helper(T source_vertex, Stack<T> *visited) {
  int items_length = visited->get_count_of_items();

  if (items_length != rear) {
    if (!visited->contains(source_vertex)) {
      visited->insert(source_vertex);
    }

    int src_index = adjacency_list->hash(source_vertex);
    node<T, T, U> *current_node = adjacency_list->get_storage()[src_index].get_item_at(0);

    while (current_node != NULL) {
      if (!visited->contains(current_node->data.key)) {
        dfs_helper(current_node->data.key, visited);
      }

      current_node = current_node->next;
    }
  }
}

template <class T, class U>
Stack<T> *AdjacencyList<T, U>::depth_first_search(T vertex) {
  Stack<T> *visited = new Stack<T>(rear);
  visited->insert(vertex);

  dfs_helper(vertex, visited);
  return visited;
}





