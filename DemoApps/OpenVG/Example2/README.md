<!-- #AG_DEMOAPP_HEADER_BEGIN# -->
# Example2
<img src="./Example.jpg" height="135px" style="float:right">

<!-- #AG_DEMOAPP_HEADER_END# -->
<!-- #AG_BRIEF_BEGIN# -->
This sample builds on top of Example1 and shows how to add color to the path strokes and
the path fill area by introducing the concept of "paints" in OpenVG.

.

.
<!-- #AG_BRIEF_END# -->

Check the following lines to see how the color was added to the red triangle:
```C++
m_vg_triangle_paint = vgCreatePaint();
vgSetParameteri(m_vg_triangle_paint, VG_PAINT_TYPE, VG_PAINT_TYPE_COLOR);
vgSetColor(m_vg_triangle_paint, 0xFF0000FF);
```

<!-- #AG_DEMOAPP_COMMANDLINE_ARGUMENTS_BEGIN# -->

Command line arguments':

Argument                       |Description                                                                                                                                                          |Source
-------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------|---------------
--DisplayId \<arg>             |DisplayId \<number>                                                                                                                                                  |DemoHost
--EGLAlphaSize \<arg>          |Force EGL_ALPHA_SIZE to the given value                                                                                                                              |DemoHost
--EGLBlueSize \<arg>           |Force EGL_BLUE_SIZE to the given value                                                                                                                               |DemoHost
--EGLDepthSize \<arg>          |Force EGL_DEPTH_SIZE to the given value                                                                                                                              |DemoHost
--EGLGreenSize \<arg>          |Force EGL_GREEN_SIZE to the given value                                                                                                                              |DemoHost
--EGLLogConfig                 |Output the EGL config to the log                                                                                                                                     |DemoHost
--EGLRedSize \<arg>            |Force EGL_RED_SIZE to the given value                                                                                                                                |DemoHost
--Window \<arg>                |Window mode [left,top,width,height]                                                                                                                                  |DemoHost
--AppFirewall                  |Enable the app firewall, reporting crashes on-screen instead of exiting                                                                                              |DemoHostManager
--ContentMonitor               |Monitor the Content directory for changes and restart the app on changes. WARNING: Might not work on all platforms and it might impact app performance (experimental)|DemoHostManager
--ExitAfterFrame \<arg>        |Exit after the given number of frames has been rendered                                                                                                              |DemoHostManager
--ForceUpdateTime \<arg>       |Force the update time to be the given value in microseconds (can be useful when taking a lot of screen-shots). If 0 this option is disabled                          |DemoHostManager
--LogStats                     |Log basic rendering stats (this is equal to setting LogStatsMode to latest)                                                                                          |DemoHostManager
--LogStatsMode \<arg>          |Set the log stats mode, more advanced version of LogStats. Can be disabled, latest, average                                                                          |DemoHostManager
--ScreenshotFrequency \<arg>   |Create a screenshot at the given frame frequency                                                                                                                     |DemoHostManager
--Stats                        |Display basic frame profiling stats                                                                                                                                  |DemoHostManager
--Profiler.AverageEntries \<arg>|The number of frames used to calculate the average frame-time. Defaults to: 60                                                                                       |ProfilerService
--ghelp \<arg>                 |Display option groups: all, demo or host                                                                                                                             |base
-h, --help                     |Display options                                                                                                                                                      |base
-v, --verbose                  |Enable verbose output                                                                                                                                                |base
<!-- #AG_DEMOAPP_COMMANDLINE_ARGUMENTS_END# -->