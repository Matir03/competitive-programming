#include<bits/stdc++.h>
using namespace std;

#define INF 10000000

struct bNode
{
    bNode* child[2];

    int height;
    int id;
};

typedef pair<int, vector<int> > idv;

bNode* tree[100000][17];
int v2[100000], lg[100000];
string zero[17];

string z0(int n)
{
    string r;
    int k = 0;

    while(n>0)
    {
        r += zero[k];
        ++k;
        n >>= 1;
    }

    return r;
}

idv better(idv a, idv b)
{
    if(a.first == INF)
        return b;

    int i = 0;

    while(true)
    {
        if(i == (a.second).size()) return a;

        if(a.second[i] > b.second[i]) return a;
        if(a.second[i] < b.second[i]) return b;

        ++i;
    }
}

idv eval(bNode* tmp, string s)
{
    vector<int> q;
    int i;

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

    return idv(tmp->id, q);
}

int best(int l, int r, string s)
{
    idv currbest(INF, vector<int>());

    int i = l, k;

    while(i<r)
    {
        k = min(v2[i], lg[r-i]);
        currbest = better(currbest, eval(tree[i][k], s));
        i += 1<<k;
    }

    return currbest.first+1;
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
            tmp->id = id;
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

            tmp->id = id;
        }
    }

    return root;
}

void makeTree(int n)
{
    int i, p, pot = 1;

    for(i=1;i<=16;++i)
    {
        for(p=0;p<=n-2*pot;p+=2*pot)
            tree[p][i] = mergeTree(tree[p][i-1], tree[p+pot][i-1]);

        pot <<= 1;
    }
}

int main()
{
    int n, q, i, j, l, r, k = 1, h=0;
    bNode* tmp;
    string s;
    ios_base::sync_with_stdio(false);

    cin >> n >> q;

    zero[0] = "0";

    for(i=1;i<=16;++i)
    {
        k <<= 1;

        for(j=0;j<n;j+=k)
            ++v2[j];

        for(j=k;j<=n;++j)
            ++lg[j];

        zero[i] = zero[i-1] + zero[i-1];
    }

    for(i=0;i<n;++i)
    {
        cin >> s;

        tree[i][0] = (bNode*)malloc(sizeof(bNode));
        tmp = tree[i][0];

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

        if(s.length()>h) h = s.length();
    }

    makeTree(n);

    while(q--)
    {
        cin >> l >> r >> s;

        cout << best(l-1, r,z0(h-s.length()) + s) << '\n';
    }
}

