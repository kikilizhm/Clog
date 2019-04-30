#define LOG_ITEM  0x10000

#define LOG_LENGTH  256

/* 使用 */
typedef struct tagLOG_BUFF_S
{
    int bufftail;
    unsigned char szBuff[LOG_ITEM][LOG_LENGTH];
    int magicword;

}LOG_BUFF_S;