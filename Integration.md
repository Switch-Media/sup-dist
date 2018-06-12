# SwitchUniversalPlayer

## Dynamic Framework

### Installation

1. Add `SwitchUniversalPlayer.framework` into project navigator

2. Add it into `Embedded Binaries` section in target setting

3. Set `Enable Bitcode` to `NO` in `Build settings`

4. On the `Build Phases` tab, add a `Run Script` phase with the command:

   ```
   bash ${BUILT_PRODUCTS_DIR}/${FRAMEWORKS_FOLDER_PATH}/SwitchUniversalPlayer.framework/strip-frameworks.sh
   ```

   Check `Run script only when installing`. This will remove unneeded architectures from the build, which is important for App Store submission.

5. Integrate with:

   1. Google cast SDK: `google-cast-sdk ~> 3.5.0`
   2. Google Ads IMA SDK: `GoogleAds-IMA-iOS-SDK ~> 3.6.0`



### Usage

In place you want to use player logic:

**Objective-C**

```objc
@import SwitchUniversalPlayer;
```

**Swift**

```swift
import SwitchUniversalPlayer
```





## Static Library

### Installation

1. Add `libSwitchUniversalPlayer.a` into project
2. Add header files from `libs/Headers` into project