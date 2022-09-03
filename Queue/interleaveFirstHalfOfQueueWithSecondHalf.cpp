// https://www.youtube.com/watch?v=_gJ3to4RyeQ&list=PLDzeHZWIZsTrhXYYtx4z8-u8zA-DzuVsj&index=8
// https://www.codingninjas.com/codestudio/problems/interleave-the-first-half-of-the-queue-with-the-second-half_1169450?leftPanelTab=0

void interLeaveQueue(queue<int> &q)
{
    // Write your code here.
    int size = q.size();
    vector<int> temp(size + 1);

    for (int i = 1; i <= size; i++)
    {
        temp[i] = q.front();
        q.pop();
    }

    for (int fp = 1, sp = size / 2 + 1; fp < size / 2 + 1, sp < size + 1; fp++, sp++)
    {
        q.push(temp[fp]);
        q.push(temp[sp]);
    }
    //     queue<int> fq,sq;
    //     int size = q.size();
    //     for(int i=1;i<= size / 2;i++) {
    //         fq.push(q.front());
    //         q.pop();
    //     }
    //     while(!q.empty()) {
    //         sq.push(q.front());
    //         q.pop();
    //     }

    //     while(!fq.empty() and !sq.empty()) {
    //         q.push(fq.front());
    //         q.push(sq.front());
    //         fq.pop();
    //         sq.pop();
    //     }
}