# InDesign Plug-In

**I'll add various things to ExtendScript.**
<br>**Let's learn the InDesign SDK together.**

We cannot be held responsible for any issues arising from your use of this service.<br>
Please use it at your own risk.<br>

note:<br>
When using ::GetGlobalMouseLocation() on Windows<br>
Visual Studio : <br>
Right-click on the project<br>
Properties > Configuration Properties > Linker > Input > Additional Dependencies<br>
$(UI_PLUGIN_LINKLIST)<br>

on Mac<br>
Build Phases > Link Binary With Libraries<br>
DV_WidgetBinLib.dylib<br>
CoreGraphics.framework<br>

## extendScript for JavaScript
```
// Query pasteboardMouseLocation.
var pasteboardLocationX = app.activeWindow.kesmlPasteboardMouseLocationX;
var pasteboardLocationY = app.activeWindow.kesmlPasteboardMouseLocationY;

// Use KohakuExtendScriptLayoutViewLocation PlugIn.
// Set locationAtFrameCenter
app.activeWindow.keslvlLocationAtFrameCenterX = pasteboardLocationX;
app.activeWindow.keslvlLocationAtFrameCenterY = pasteboardLocationY;

// Set pasteboardMouseLocation.
app.activeWindow.kesmlPasteboardMouseLocationX = pasteboardLocationX;
app.activeWindow.kesmlPasteboardMouseLocationY = pasteboardLocationY;

```
