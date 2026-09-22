class Solution {
    struct Node {
        int prod = 1;
        int cnt[5] = {};
    };

    int k;
    vector<Node> tree;

    Node merge(Node left, Node right) {
        Node res;

        res.prod = (left.prod * right.prod) % k;

        for (int r = 0; r < k; r++)
            res.cnt[r] = left.cnt[r];

        for (int r = 0; r < k; r++) {
            int rem = (left.prod * r) % k;
            res.cnt[rem] += right.cnt[r];
        }

        return res;
    }

    void build(vector<int>& nums, int node, int l, int r) {
        if (l == r) {
            int v = nums[l] % k;
            tree[node].prod = v;
            tree[node].cnt[v] = 1;
            return;
        }

        int mid = (l + r) / 2;

        build(nums, node * 2, l, mid);
        build(nums, node * 2 + 1, mid + 1, r);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int node, int l, int r, int pos, int value) {
        if (l == r) {
            value %= k;
            tree[node].prod = value;

            for (int i = 0; i < k; i++)
                tree[node].cnt[i] = 0;

            tree[node].cnt[value] = 1;
            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid)
            update(node * 2, l, mid, pos, value);
        else
            update(node * 2 + 1, mid + 1, r, pos, value);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    Node query(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr)
            return tree[node];

        int mid = (l + r) / 2;

        if (qr <= mid)
            return query(node * 2, l, mid, ql, qr);

        if (ql > mid)
            return query(node * 2 + 1, mid + 1, r, ql, qr);

        Node left = query(node * 2, l, mid, ql, qr);
        Node right = query(node * 2 + 1, mid + 1, r, ql, qr);

        return merge(left, right);
    }

public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        this->k = k;

        int n = nums.size();
        tree.resize(4 * n);

        build(nums, 1, 0, n - 1);

        vector<int> ans;

        for (auto& q : queries) {
            update(1, 0, n - 1, q[0], q[1]);

            Node res = query(1, 0, n - 1, q[2], n - 1);

            ans.push_back(res.cnt[q[3]]);
        }

        return ans;
    }
};