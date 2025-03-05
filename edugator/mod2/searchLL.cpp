int find(Node* node, int valueInput)
{
  int count = 0;
  Node* iter = node;
  while(iter) {
    if (iter->value == valueInput) {
      return count; 
    }
      iter = iter->next; 
      count++;
  }

  return -1;
}
