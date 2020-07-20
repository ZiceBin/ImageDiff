## 没有写自己的代码，复制的 https://cloud.tencent.com/developer/article/1438942 的代码，看看效果
## 依赖 opencv-python, numpy, scikit-image包

import numpy as np
import matplotlib.pyplot as plt
from skimage.measure import compare_ssim
import cv2


origin = cv2.imread('c.jpg', 0)
dark = (origin*0.9).astype('uint8')
blur = cv2.GaussianBlur(origin, (5,5), 0)

# mse_dark = np.mean((origin-dark)**2)
# mse_blur = np.mean((origin-blur)**2)
ssim_dark = compare_ssim(origin, dark)
ssim_blur = compare_ssim(origin, blur)

fig, axes = plt.subplots(1, 3)
axes[0].imshow(origin, 'gray')
axes[0].title.set_text('origin')
axes[0].axis('off')

axes[1].imshow(dark, 'gray')
axes[1].title.set_text('0.9 dark ssim: {:.2f}'.format(ssim_dark))
axes[1].axis('off')

axes[2].imshow(blur, 'gray')
axes[2].title.set_text('blur ssim: {:.2f}'.format(ssim_blur))
axes[2].axis('off')

plt.show()

print('SSIM dark : {}'.format(ssim_dark))
print('SSIM blur : {}'.format(ssim_blur))