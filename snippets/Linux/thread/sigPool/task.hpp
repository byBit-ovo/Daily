
void net_ask()
{
    LOG(logLevel::INFO) << "网络请求任务正在被执行...";
}

void log_push()
{
    LOG(logLevel::INFO) << "日志推送任务任务正在被执行...";
    sleep(10);
}

void data_parse()
{
    LOG(logLevel::INFO) << "数据分析任务正在被执行...";
}

void game()
{
    LOG(logLevel::INFO) << "这个线程竟然在偷偷玩游戏...";
}


