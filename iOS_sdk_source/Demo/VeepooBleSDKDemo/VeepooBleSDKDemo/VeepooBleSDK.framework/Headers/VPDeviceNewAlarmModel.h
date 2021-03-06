//
//  VPDeviceNewAlarmModel.h
//  VeepooBleSDK
//
//  Created by 张冲 on 17/6/15.
//  Copyright © 2017年 veepoo. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface VPDeviceNewAlarmModel : NSObject<NSCopying>
//闹钟小时
@property (nonatomic, strong) NSString *alarmHour;
//闹钟分钟
@property (nonatomic, strong) NSString *alarmMinute;
//闹钟状态，0代表关闭 1代表开启
@property (nonatomic, strong) NSString *alarmState;
//闹钟ID，增删改查都需要用到这个
@property (nonatomic, strong) NSString *alarmID;
//闹钟重复状态，0代表不重复要设置一个闹钟提醒的日期，其他情况是由8位2进制转换成10进制的字符串如：00000011，代表重复星期是周一和周二，repeatState就是3；二进制从后边往前推，开头的第一位一直为0，其他的一次代表周一至周日，第2位是周日，最后一位是周一，1代表重复，0代表这个星期不重复
@property (nonatomic, strong) NSString *repeatState;
//闹钟提醒的场景，0-20
@property (nonatomic, strong) NSString *alarmScene;
//闹钟提醒的日期，对单次提醒有效，重复星期提醒的默认给0000-00-00，所有格式都是这样的
@property (nonatomic, strong) NSString *alarmDate;

- (instancetype)initWithAlarmDict:(NSDictionary *)alarmDict;

+ (NSDictionary *)getAlarmDictWithTbyte:(const uint8_t *)tbyte;

+ (NSArray *)changeNewAlarmArray:(NSArray *)saveAlarmArray;

- (NSDictionary *)changeModelToDict;

- (NSData *)changeModelToSettingAlarmDataWithType:(short)type;

- (NSString *)getRepeatWeek;

//把dictArray转换成ModelArray
+ (NSArray *)changeModelArrayWithAlarmDictArray:(NSArray *)alarmArray;

//把星期转换成二进制的字符串，方便显示
- (NSString *)weekBinaryString;

@end






