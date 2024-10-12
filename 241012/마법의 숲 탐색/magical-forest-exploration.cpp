#include <iostream>
#include <algorithm>

using namespace std;

int R, C, K;
int c, d;
// 0,1,2,3 북 동 남 서
int fy, fx;
int ret;

int arr[74][74];
int door[74][74];
bool visited[74][74];
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};

bool isValidLocation(int y, int x){

    if( 0 <= y && y <= 2)
        return false;

    for(int i=0; i<4; i++){
        int ny = y+ dy[i];

        if(0 <= ny && ny <=2)
            return false;
    }

    return true;
}

void eraseCurLocation(int y, int x){
    arr[y][x] = 0;
    for(int i =0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        arr[ny][nx] = 0;
    }
}

void moveDown(int y, int x, int curIdx){
    eraseCurLocation(y,x);

    door[y + dy[d]][x + dx[d]] = 0;

    y = y+1;
    x = x;

    fy = y;
    fx = x;

    arr[y][x] = curIdx;
    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        arr[ny][nx] = curIdx;
    }

    door[y + dy[d]][x + dx[d]] = 1;
}

void moveRight(int y, int x, int curIdx){
    eraseCurLocation(y,x);

    door[y + dy[d]][x + dx[d]] = 0;

    y = y+1;
    x = x+1;

    fy = y;
    fx = x;

    arr[y][x] = curIdx;
    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        arr[ny][nx] = curIdx;
    }

    d = (d+5) % 4;

    door[y + dy[d]][x + dx[d]] = 1;
}

void moveLeft(int y, int x, int curIdx){
    eraseCurLocation(y,x);

    door[y + dy[d]][x + dx[d]] = 0;

    y = y+1;
    x = x-1;

    fy = y;
    fx = x;

    arr[y][x] = curIdx;
    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        arr[ny][nx] = curIdx;
    }

    d = (d+3) % 4;

    door[y + dy[d]][x + dx[d]] = 1;
}

// 이동 가능 체크
// 1. 아래이동
bool canDown(int y, int x, int curIdx){
    // 왼쪽 아래
    int y1 = y+1;
    int x1 = x-1;

    if(y1 < 0 || y1 >=R+3 || x1 < 0 || x1 >= C || (arr[y1][x1] != 0 && arr[y1][x1] != curIdx))
        return false;

    // 가운데 아래
    int y2 = y+2;
    int x2 = x;

    if(y2 < 0 || y2 >=R+3 || x2 < 0 || x2 >= C || (arr[y2][x2] != 0 && arr[y2][x2] != curIdx))
        return false;

    // 오른쪽 아래
    int y3 = y+1;
    int x3 = x+1;

    if(y3 < 0 || y3 >=R+3 || x3 < 0 || x3 >= C || (arr[y3][x3] != 0 && arr[y3][x3] != curIdx))
        return false;

    return true;
}

// 2. 왼쪽 + 아래 이동
bool canLeft(int y, int x, int curIdx){
    // 왼쪽 위
    int y1 = y-1;
    int x1 = x-1;

    if(y1 < 0 || y1 >=R+3 || x1 < 0 || x1 >= C || (arr[y1][x1] != 0 && arr[y1][x1] != curIdx))
        return false;

    // 왼쪽 가운데
    int y2 = y;
    int x2 = x-2;

    if(y2 < 0 || y2 >=R+3 || x2 < 0 || x2 >= C || (arr[y2][x2] != 0 && arr[y2][x2] != curIdx))
        return false;

    // 왼쪽 아래
    int y3 = y+1;
    int x3 = x-1;

    if(y3 < 0 || y3 >=R+3 || x3 < 0 || x3 >= C || (arr[y3][x3] != 0 && arr[y3][x3] != curIdx))
        return false;

    return true;
}

// 3. 오른쪽 + 아래 이동
bool canRight(int y, int x, int curIdx){
    // 오른쪽 아래
    int y1 = y+1;
    int x1 = x+1;

    if(y1 < 0 || y1 >=R+3 || x1 < 0 || x1 >= C || (arr[y1][x1] != 0 && arr[y1][x1] != curIdx))
        return false;

    // 오른쪽 중간
    int y2 = y;
    int x2 = x+2;

    if(y2 < 0 || y2 >=R+3 || x2 < 0 || x2 >= C || (arr[y2][x2] != 0 && arr[y2][x2] != curIdx))
        return false;

    // 오른쪽 위
    int y3 = y-1;
    int x3 = x+1;

    if(y3 < 0 || y3 >=R+3 || x3 < 0 || x3 >= C || (arr[y3][x3] != 0 && arr[y3][x3] != curIdx))
        return false;

    return true;
}

void printArr(){
    cout << "\n";
    for(int i=0; i<R+3; i++){
        for(int j=0; j<C; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

void printDoor(){
    cout << "문\n";
    for(int i=0; i<R+3; i++){
        for(int j=0; j<C; j++){
            cout << door[i][j] << " ";
        }
        cout << "\n";
    }
}

void move(int y, int x, int curIdx){
    //printArr();
    while(true){
        bool moved = false;

        // 내려가기
        if(canDown(y, x, curIdx)){
            moveDown(y,x, curIdx);
            y = y +1;
            x = x;
            moved = true;
        }

        // 왼쪽으로 내려가기
        if(moved == false && canLeft(y,x, curIdx) && canDown(y, x-1, curIdx)){
            moveLeft(y,x, curIdx);
            y = y + 1;
            x = x - 1;
            moved = true;
        }

        // 오른쪽으로 내려가기
        if(moved == false && canRight(y,x, curIdx) && canDown(y, x+1, curIdx)){
            moveRight(y,x, curIdx);
            y = y + 1;
            x = x + 1;
            moved = true;
        }

        if(moved == false){
            //printDoor();
            break;
        }
    }
}

int dfs(int y, int x){
    visited[y][x] = true;
    int ry = y;

    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny <3 || ny >= R + 3 || nx < 0 || nx >= C || visited[ny][nx] || arr[ny][nx] == 0)
            continue;

        if(arr[y][x] != arr[ny][nx] && door[y][x] == 0)
            continue;
        
        ry = max(dfs(ny,nx), ry);
    }   


    return ry; 
}

void eraseAll(){
    for(int i=0; i<R+3; i++)
        for(int j=0; j<C; j++){
            arr[i][j] = 0;
            door[i][j] = 0;
        }
}


int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C >> K;

    for(int i=1; i<=K; i++){
        cin >> c >> d;

        //초기 요정 위치 세팅
        fy = 1;
        fx = c-1;

        //초기 골렘 위치 세팅
        arr[fy][fx] = i;
        for(int j=0; j<4; j++){
            int ny = fy + dy[j];
            int nx = fx + dx[j];

            arr[ny][nx] = i;
        }

        // 출구 위치 세팅
        door[fy + dy[d]][fx + dx[d]] = 1;

        //골렘 이동
        move(1, c-1, i);

        //골렘 범위 체크
        if(!isValidLocation(fy, fx)){
            eraseAll();
            continue;
        }

        //요정 이동
        fill(&visited[0][0], &visited[0][0] + 71*71, false);
        ret += (dfs(fy, fx)-2);

    }

    cout << ret << "\n";

}

// 이동 가능 체크
// 1. 아래이동
// 2. 왼쪽 + 아래 이동
// 3. 오른쪽 + 아래 이동

// 이동
// 1. 아래이동
// 2. 왼쪽 이동(출구방향 변경)
// 3. 오른쪽 이동(출구방향 변경)

// 범위 밖 체크
// 1. 범위 밖 체크

// 요정 이동
// 1. dfs로 이동 후 최대 R값 저장