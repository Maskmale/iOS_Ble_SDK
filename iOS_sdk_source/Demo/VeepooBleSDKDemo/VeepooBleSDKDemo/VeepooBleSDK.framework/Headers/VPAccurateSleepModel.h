//
//  VPAccurateSleepModel.h
//  WYPHealthyThird
//
//  Created by 张冲 on 2018/10/11.
//  Copyright © 2018年 veepoo. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface VPAccurateSleepModel : NSObject

//睡眠的类型，上传A7指令睡眠标记位
@property (nonatomic, strong) NSString *sleepType;
//入睡时间
@property (nonatomic, strong) NSString *sleepTime;
//起床时间
@property (nonatomic, strong) NSString *wakeTime;
//睡眠标志
@property (nonatomic, strong) NSString *sleepTag;
//起夜得分
@property (nonatomic, strong) NSString *getUpScore;
//深睡得分
@property (nonatomic, strong) NSString *deepScore;
//睡眠效率得分，起夜到深睡的效率得分
@property (nonatomic, strong) NSString *sleepEfficiencyScore;
//入睡效率得分，从开始睡眠到第一次进入深睡的效率
@property (nonatomic, strong) NSString *fallAsleepScore;

//睡眠时长得分
@property (nonatomic, strong) NSString *sleepTimeScore;
//退出睡眠的模式
@property (nonatomic, strong) NSString *exitSleepMode;
//睡眠质量0到4, 依次代表1到5颗星
@property (nonatomic, strong) NSString *sleepQuality;
//起夜次数
@property (nonatomic, strong) NSString *getUpTimes;
//深浅睡眠模式
@property (nonatomic, strong) NSString *deepAndLightMode;
//睡眠总时长，单位分钟
@property (nonatomic, strong) NSString *sleepDuration;
//深睡时间，单位分钟
@property (nonatomic, strong) NSString *deepDuration;
//浅睡时间，单位分钟
@property (nonatomic, strong) NSString *lightDuration;
//起夜时间，单位分钟
@property (nonatomic, strong) NSString *getUpDuration;
//其他睡眠时间，单位分钟
@property (nonatomic, strong) NSString *otherDuration;
//第一次进入深睡时间
@property (nonatomic, strong) NSString *firstDeepDuration;
//起夜到深睡时间的平均值
@property (nonatomic, strong) NSString *getUpToDeepAve;
//曲线上一个点代表的时间，单位秒，现在是60s
@property (nonatomic, strong) NSString *onePointDuration;
//精准睡眠类型, 1是精准睡眠, 0是普通睡眠
@property (nonatomic, strong) NSString *accurateType;
//失眠标志
@property (nonatomic, strong) NSString *insomniaTag;
//失眠得分
@property (nonatomic, strong) NSString *insomniaScore;
//失眠次数
@property (nonatomic, strong) NSString *insomniaTimes;
//beginTime开始时间,具体开始入睡多少分钟,endTime结束时间,具体开始入睡多少分钟
@property (nonatomic, strong) NSArray *insomniaRecord;
//睡眠曲线，16进制的字符串，客户端解析的时候在转换成数据流，每两个字节代表一个点。
@property (nonatomic, strong) NSString *sleepLine;

//根据曲线转换的失眠时长
@property (nonatomic, strong) NSString *insomniaDuration;

@property (nonatomic, strong) NSString *lastType;
@property (nonatomic, strong) NSString *nextType;
@property (nonatomic, strong) NSString *mac;

//根据读取的数据创建模型，如果返回nil代表数据解析失败
+ (instancetype)modelWithAccurateSleepData:(NSData *)accurateSleepData dayNumber:(NSInteger)dayNumber sleepType:(NSInteger)sleepType;

- (int)getUpSleepPercent;
- (int)insomniaPercent;
- (int)eyeMovementPercent;
- (int)lightSleepPercent;
- (int)deepSleepPercent;


@end

NS_ASSUME_NONNULL_END
