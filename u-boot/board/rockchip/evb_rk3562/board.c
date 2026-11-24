#include <dm/uclass.h>
#include <dm/device.h>
#include <common.h>

int rk_board_init(void)
{
	struct udevice *dev;
	struct udevice *lt8912_dev;
	int ret;

	ret = uclass_get_device(UCLASS_I2C, 2, &dev);
	if (ret) {
		printf("+++ HzDebug: Get I2c Bus Error\n");
		return 0;
	}
	//printf("+++ HzDebug: Get I2c Bus OK\n");
	
	/*
	// 手动遍历 I2C 设备并计数（替代 uclass_get_device_count）
	int i2c_device_count = 0;
	for (uclass_first_device(UCLASS_I2C, &allI2cDev);
			allI2cDev;
			uclass_next_device(&allI2cDev)) {
		printf("+ Device: %s\n", allI2cDev->name);
		i2c_device_count++;
	}
	printf("++++ I2C device count: %d\n", i2c_device_count);
	*/

	ret = uclass_get_device(UCLASS_I2C_GENERIC, 0, &lt8912_dev);
	if (ret) {
		printf("+++ HzDebug: Get I2c Device Error\n");
		return 0;
		
	}
	//printf("+++ HzDebug: Get I2c Device OK. Name: %s\n", lt8912_dev->name);

	return 0;
}
