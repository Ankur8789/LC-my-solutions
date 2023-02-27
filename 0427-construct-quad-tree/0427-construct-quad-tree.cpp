class Solution
{
public:
    Node *helper(vector<vector<int>> &grid, int rs, int re, int cs, int ce)
    {
        int count1 = 0;
        for (int i = rs; i <= re; i++)
        {
            for (int j = cs; j <= ce; j++)
            {
                if (grid[i][j] == 1)
                    count1++;
            }
        }
        if (count1 == (re - rs + 1) * (ce - cs + 1))
        {
            Node *temp = new Node(1, 1);

            return temp;
        }
        else if (count1 == 0)
        {
            Node *temp = new Node(0, 1);

            return temp;
        }

        Node *temp = new Node(1, 0);
        temp->topLeft = helper(grid, rs, (rs + re) / 2, cs, (cs + ce) / 2);
        temp->topRight = helper(grid, rs, (rs + re) / 2, (cs + ce) / 2 + 1, ce);
        temp->bottomLeft = helper(grid, (rs + re) / 2 + 1, re, cs, (cs + ce) / 2);
        temp->bottomRight = helper(grid, (rs + re) / 2 + 1, re, (cs + ce) / 2 + 1, ce);

        return temp;
    }
    Node *construct(vector<vector<int>> &grid)
    {
        return helper(grid, 0, grid.size() - 1, 0, grid.size() - 1);
    }
};