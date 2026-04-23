#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>
#include <time.h>
#include <string.h>
#include <thread>

#pragma comment(lib, "ws2_32.lib")

#define PORT 8888
#define MAX_PLAYERS 2

int secret_number = 0;
int player_scores[MAX_PLAYERS] = {0};
int current_round = 0;

void clear_buffer()
{
    while(getchar() != '\n');
}

void client_handler(SOCKET client_socket, int player_id)
{
    char buffer[1024];
    int score = 10;
    int guesses = 0;
    
    printf("Player %d 已连接\n", player_id + 1);
    
    // 发送欢迎消息
    sprintf(buffer, "欢迎 Player %d! 开始猜数字(1-100)...\n", player_id + 1);
    send(client_socket, buffer, strlen(buffer), 0);
    
    // 游戏循环
    for(;;)
    {
        if(score <= 0)
        {
            sprintf(buffer, "分数不足，游戏结束！\n");
            send(client_socket, buffer, strlen(buffer), 0);
            break;
        }
        
        // 接收玩家输入
        memset(buffer, 0, sizeof(buffer));
        int bytes = recv(client_socket, buffer, sizeof(buffer), 0);
        
        if(bytes <= 0) break;
        
        int inp = atoi(buffer);
        guesses++;
        
        if(inp < secret_number)
        {
            sprintf(buffer, "太小了! 扣1分\n");
            score--;
        }
        else if(inp > secret_number)
        {
            sprintf(buffer, "太大了! 扣1分\n");
            score--;
        }
        else
        {
            sprintf(buffer, "恭喜猜中! 第%d次猜对! 加1分\n", guesses);
            score++;
            break;
        }
        
        sprintf(buffer + strlen(buffer), "剩余分数: %d\n", score);
        send(client_socket, buffer, strlen(buffer), 0);
    }
    
    player_scores[player_id] = score;
    closesocket(client_socket);
    printf("Player %d 断开连接，分数: %d\n", player_id + 1, score);
}

int main()
{
    WSADATA wsa_data;
    SOCKET server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    int client_addr_len = sizeof(client_addr);
    int player_count = 0;
    
    printf("========== 猜数字游戏服务器 ==========\n");
    printf("正在启动服务器...\n");
    
    // 初始化Winsock
    if(WSAStartup(MAKEWORD(2, 2), &wsa_data) != 0)
    {
        printf("WSAStartup 失败!\n");
        return 1;
    }
    
    // 创建socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(server_socket == INVALID_SOCKET)
    {
        printf("创建socket失败!\n");
        WSACleanup();
        return 1;
    }
    
    // 绑定端口
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    
    if(bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == SOCKET_ERROR)
    {
        printf("绑定端口失败!\n");
        closesocket(server_socket);
        WSACleanup();
        return 1;
    }
    
    // 监听连接
    listen(server_socket, MAX_PLAYERS);
    printf("服务器运行在 127.0.0.1:%d\n", PORT);
    printf("等待玩家连接...\n");
    printf("=====================================\n");
    
    srand(time(NULL));
    
    // 接受连接
    while(1)
    {
        printf("\n========== 新一轮开始 ==========\n");
        secret_number = rand() % 100 + 1;
        player_count = 0;
        memset(player_scores, 0, sizeof(player_scores));
        
        std::thread threads[MAX_PLAYERS];
        
        // 等待两个玩家连接
        for(int i = 0; i < MAX_PLAYERS; i++)
        {
            client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);
            
            if(client_socket == INVALID_SOCKET)
            {
                printf("接受连接失败!\n");
                continue;
            }
            
            printf("客户端已连接: %s\n", inet_ntoa(client_addr.sin_addr));
            
            // 为每个客户端创建线程
            threads[i] = std::thread(client_handler, client_socket, i);
            threads[i].detach();
        }
        
        // 等待所有玩家完成
        Sleep(5000);
        
        // 显示结果
        printf("\n========== 对战结果 ==========\n");
        printf("Player 1 分数: %d\n", player_scores[0]);
        printf("Player 2 分数: %d\n", player_scores[1]);
        
        if(player_scores[0] > player_scores[1])
            printf("Player 1 获胜!\n");
        else if(player_scores[1] > player_scores[0])
            printf("Player 2 获胜!\n");
        else
            printf("平局!\n");
        printf("================================\n");
    }
    
    closesocket(server_socket);
    WSACleanup();
    return 0;
}