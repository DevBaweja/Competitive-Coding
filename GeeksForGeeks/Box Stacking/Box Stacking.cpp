#include <bits/stdc++.h>
using namespace std;

struct Box
{
    int h;
    int l;
    int w;
};

static int compare(Box a, Box b)
{
    return (a.l * a.w) > (b.l * b.w);
}

int maxHeight(int height[], int length[], int width[], int n)
{
    vector<Box> boxes(3 * n);
    for (int i = 0; i < n; i++)
    {
        boxes[3 * i].h = height[i];
        boxes[3 * i].l = max(length[i], width[i]);
        boxes[3 * i].w = min(length[i], width[i]);

        boxes[3 * i + 1].h = length[i];
        boxes[3 * i + 1].l = max(height[i], width[i]);
        boxes[3 * i + 1].w = min(height[i], width[i]);

        boxes[3 * i + 2].h = width[i];
        boxes[3 * i + 2].l = max(length[i], height[i]);
        boxes[3 * i + 2].w = min(length[i], height[i]);
    }

    n = 3 * n;
    sort(boxes.begin(), boxes.end(), compare);

    vector<int> msh(n, 0);

    // Longest Increasing Subsequence
    int res = -1;
    for (int i = 0; i < n; i++)
    {
        int sub = boxes[i].h;
        for (int j = 0; j < i; j++)
        {
            if (boxes[i].l < boxes[j].l &&
                boxes[i].w < boxes[j].w)
                sub = max(sub, msh[j] + boxes[i].h);
        }
        msh[i] = sub;
        res = max(res, msh[i]);
    }
    return res;
}