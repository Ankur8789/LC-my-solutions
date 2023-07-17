class Solution
{
public:
    string add(string &x, string &y, string &ans)
    {
        int flag = 0;
        int i;
        string str1 = "";
        int j = 0;
        while (x[j] == '0')
        {
            j++;
        }
        while (j < x.size())
        {
            str1 += x[j];
            j++;
        }
        string str2 = "";
        j = 0;
        while (y[j] == '0')
        {
            j++;
        }
        while (j < y.size())
        {
            str2 += y[j];
            j++;
        }
        i = str1.size() - 1, j = str2.size() - 1;
        if (str1.size() == 0 and str2.size() == 0)
        {
            return "0";
        }
        while (i >= 0 or j >= 0)
        {
            if (i >= 0 and j >= 0)
            {
                int r = (str1[i] - '0') + (str2[j] - '0');
                r += flag;
                flag = r / 10;
                string res = to_string(r % 10);
                ans += res;
                i--;
                j--;
            }
            else if (j >= 0)
            {
                int r = (str2[j] - '0') + flag;
                flag = r / 10;
                ans += to_string(r % 10);
                j--;
            }
            else if (i >= 0)
            {
                int r = (str1[i] - '0') + flag;
                flag = r / 10;
                ans += to_string(r % 10);
                i--;
            }
        }
        if (flag > 0)
        {
            ans += to_string(flag);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        string x = "", y = "", ans = "";
        while (l1 != NULL)
        {
            x += to_string(l1->val);
            l1 = l1->next;
        }
        while (l2 != NULL)
        {
            y += to_string(l2->val);
            l2 = l2->next;
        }
        add(x, y, ans);
        int i = 0;
        ListNode *list = new ListNode();
        ListNode *anss = list;
        int cnt = 0;
        while (i < ans.size())
        {
            int r = ans[i] - '0';
            ListNode *node = new ListNode(r);
            anss->next = node;
            anss = anss->next;
            i++;
            cnt++;
        }
        if (cnt == 0)
        {
            return list;
        }
        return list->next;
    }
};
