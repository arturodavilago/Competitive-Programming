#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,inline")
#include <bits/stdc++.h>
using namespace std;
#define fore(i, l, r)  \
for (auto i = (l) - ((l) > (r)); \
          i != (r) - ((l) > (r)); \
          i += 1 - 2 * ((l) > (r)))
#define sz(x) int((x).size())
#define all(x) begin((x)), end((x))

#define debug(...)
#define debx(...) (__VA_ARGS__)
#ifdef LOCAL
#include "debug.h"
#endif
using ld = long double;
using lli = long long;


struct Node {
    lli sum;
    Node *left, *right;

    Node(lli sum = 0) : sum(sum), left(nullptr), right(nullptr) {}
};

// Construir el árbol inicial
Node* build(vector<lli>& a, int low, int high) {
    Node* node = new Node();

    if (low == high) {
        node->sum = a[low];
        return node;
    }

    int mid = (low + high) / 2;

    node->left = build(a, low, mid);
    node->right = build(a, mid + 1, high);

    node->sum = node->left->sum + node->right->sum;

    return node;
}

// Actualizar una posición y crear una nueva versión
Node* update(Node* curr, int low, int high, int pos, lli x) {
    Node* node = new Node(*curr);
    if (low == high) {
        node->sum = x;
        return node;
    }

    int mid = (low + high) / 2;

    if (pos <= mid)
        node->left = update(curr->left, low, mid, pos, x);
    else
        node->right = update(curr->right,  mid + 1, high, pos, x);

    node->sum = node->left->sum + node->right->sum;

    return node;
}

// Consultar suma del rango [l, r]
lli queryTwo(Node* node, int low, int high, int l, int r) {
    if (r < low || high < l || high<low)
        return 0;

    if (l <= low && high <= r)
        return node->sum;

    int mid = (low + high) / 2;

    return queryTwo(node->left, low, mid, l, r) + queryTwo(node->right, mid + 1, high, l, r);
}



int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);
    int n,q;
  cin>>n>>q;
  vector <lli> vec(n);
  vector <Node*> roots;
  fore(i,0,n){
        cin>>vec[i];
  }cin.ignore();
  roots.push_back(build(vec, 0, n-1));
  while(q--)
    {

            string s;
            getline(cin,s);
            stringstream ss(s);

            int f,k,a,b;
            ss>>f>>k;
            if(ss>>a){
                ss>>b;
                if(f==1){
                    Node* x = update(roots[k-1],0,n-1,a-1,b);
                    roots[k-1] = x;
                }
                else{
                    cout<< queryTwo(roots[k-1],0,n-1,a-1,b-1)<<endl;
                }
            }else{
                Node* cop = new Node(*roots[k-1]);
                roots.push_back(cop);
            }
  }

  return 0;
}
