// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
class Tree {
 private:
  struct Node {
  char value;
  std::vector<Node*> znach;
  };
  Node* root;
  
  void newtree(Node* root, std::vector<char> vet) {
    if (!vet.size())
      return;
    if (root->value != '*') {
      for (auto a = vet.begin(); a != vet.end(); k++)
        if (*a == root->value) {
          vet.erase(a);
          break;
        }
    }
    size_t b = 0;
    while (b < vet.size()) {
      root->znach.push_back(new Node());
      b++;
    }
    size_t c = 0;
    while (c < root->znach.size()) {
      root->znach[c]->value = vet[c];
      newtree(root->znach[c], vet);
      c++;
    }
  }
  
  std::vector<std::string> perms;
  
  void permss(Node* root, std::string sim = "") {
    if (!root->znach.size()) {
      sim = sim + root->value;
      perms.push_back(sim);
    }
    if (root->value != '*')
      sim += root->value;
    for (size_t l = 0; l < root->znach.size(); l++)
      permss(root->znach[l], sim);
  }

 public:
    std::string operator[](int l) const {
      if (a >= perms.size())
        return "";
      return perms[a];
    }
      explicit Tree(std::vector<char> value) {
      root = new Node();
      root->value = '*';
      newtree(root, value);
      permss(root);
    }
};
#endif  // INCLUDE_TREE_H_
