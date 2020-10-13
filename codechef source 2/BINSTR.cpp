#include<bits/stdc++.h>
using namespace std;

#define INF 10000000

struct bNode
{
    bNode* child[2];

    int height;
    int id;
};

struct tNode
{
    tNode* left;
    tNode* right;

    bNode* tree;
};

bNode* tree[100001];

int best(tNode* root, int x, int y, int l, int r, string s, vector<int>& q)
{
    if(y<l || x>r) return INF;

    int i = 0;

    if(x>=l && y<=r)
    {
        bNode* tmp = root->tree;

        for(i=0;i<s.length()-tmp->height;++i)
            if(s[i]=='0') q.push_back(i);

        for(i=s.length()-tmp->height;i<s.length();++i)
        {
            if(s[i]=='0')
            {
                if(tmp->child[1] != nullptr)
                    tmp = tmp->child[1];
                else
                {
                    q.push_back(i);
                    tmp = tmp->child[0];
                }
            }
            else
            {
                if(tmp->child[0] != nullptr)
                    tmp = tmp->child[0];
                else
                {
                    q.push_back(i);
                    tmp = tmp->child[1];
                }
            }
        }
        q.push_back(INF);

        return tmp->id;
    }

    int m = (x+y)/2;
    vector<int> b1, b2;

    int id1 = best( root->left,   x, m, l, r, s, b1);
    int id2 = best(root->right, m+1, y, l, r, s, b2);

    if(id1==INF)
    {
        q = b2;
        return id2;
    }
    if(id2==INF)
    {
        q = b1;
        return id1;
    }

    while(true)
    {
        if(i==b1.size()) {q = b1; return id1;}

        if(b1[i]>b2[i]) {q = b1; return id1;}
        if(b2[i]>b1[i]) {q = b2; return id2;}

        ++i;
    }
}

void printTree(string s, bNode* root)
{
    if(root->child[0] == nullptr &&
       root->child[1] == nullptr)
    {
        cout << s << ' ' << root->id << '\n';
        return;
    }

    if(root->child[0] != nullptr) printTree(s+'0', root->child[0]);
    if(root->child[1] != nullptr) printTree(s+'1', root->child[1]);
}

bNode* mergeTree(bNode* r1, bNode* r2)
{
    if(r1 == nullptr) return r2;
    if(r2 == nullptr) return r1;

    bNode* root = (bNode*)malloc(sizeof(bNode)), *tmp, *tmp2;
    int h1 = r1->height, h2 = r2->height, id = min(r1->id, r2->id);

    if(h1>h2)
    {
        root->height = h1;
        root->id = id;
        tmp  = root;
        tmp2 = r1;

        while(h1>h2)
        {
            --h1;
            tmp->child[0] = (bNode*)malloc(sizeof(bNode));

            if(tmp2 != nullptr)
            {
                tmp->child[1] = tmp2->child[1];
                tmp2 = tmp2->child[0];
            }
            else
            {
                tmp->child[1] = nullptr;
            }

            tmp = tmp->child[0];
            tmp->height = h1;
            tmp->id = id;
        }

        if(tmp2 != nullptr)
        {
            tmp->child[0] = mergeTree(tmp2->child[0], r2->child[0]);
            tmp->child[1] = mergeTree(tmp2->child[1], r2->child[1]);
        }
        else
        {
            tmp->child[0] = r2->child[0];
            tmp->child[1] = r2->child[1];
        }
    }
    else
    {
        root->height = h2;
        root->id = id;

        tmp  = root;
        tmp2 = r2;

        while(h2>h1)
        {
            --h2;
            tmp->child[0] = (bNode*)malloc(sizeof(bNode));

            if(tmp2 != nullptr)
            {
                tmp->child[1] = tmp2->child[1];
                tmp2 = tmp2->child[0];
            }
            else
            {
                tmp->child[1] = nullptr;
            }

            tmp = tmp->child[0];
            tmp->height = h2;
            tmp->id = id;
        }

        if(tmp2 != nullptr)
        {
            tmp->child[0] = mergeTree(tmp2->child[0], r1->child[0]);
            tmp->child[1] = mergeTree(tmp2->child[1], r1->child[1]);
        }
        else
        {
            tmp->child[0] = r1->child[0];
            tmp->child[1] = r1->child[1];
        }
    }

    return root;
}

tNode* makeSegTree(int x, int y)
{
    tNode* ret = (tNode*)malloc(sizeof(tNode));

    if(x==y)
    {
        ret->left  = nullptr;
        ret->right = nullptr;
        ret->tree  = tree[x];

        return ret;
    }

    int m = (x+y)/2;

    ret->left  = makeSegTree(x, m);
    ret->right = makeSegTree(m+1, y);

    ret->tree  = mergeTree(ret->right->tree, ret->left->tree);

    return ret;
}

int main()
{
    int n, q, i, j, l, r;
    bNode* tmp;
    tNode* root;
    string s;
    vector<int> holder;
    ios_base::sync_with_stdio(false);

    cin >> n >> q;

    for(i=1;i<=n;++i)
    {
        cin >> s;

        tree[i] = (bNode*)malloc(sizeof(bNode));
        tmp = tree[i];

        for(j=0;j<s.length();++j)
        {
            tmp->height = s.length()-j;
            tmp->id = i;
            if(s[j] == '0')
            {
                tmp->child[0] = (bNode*)malloc(sizeof(bNode));
                tmp->child[1] = nullptr;
                tmp = tmp->child[0];
            }
            else
            {
                tmp->child[1] = (bNode*)malloc(sizeof(bNode));
                tmp->child[0] = nullptr;
                tmp = tmp->child[1];
            }
        }

        tmp->child[0] = nullptr;
        tmp->child[1] = nullptr;
        tmp->height = 0;
        tmp->id = i;
    }

    root = makeSegTree(1, n);

    while(q--)
    {
        cin >> l >> r >> s;

        holder.clear();

        while(root->tree->height>s.length())
            s = '0' + s;

        cout << best(root, 1, n, l, r, s, holder) << '\n';
    }
}
