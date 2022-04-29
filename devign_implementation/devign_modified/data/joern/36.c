static void d3d11va_device_uninit(AVHWDeviceContext *hwdev)

{

    AVD3D11VADeviceContext *device_hwctx = hwdev->hwctx;



    if (device_hwctx->device)

        ID3D11Device_Release(device_hwctx->device);



    if (device_hwctx->device_context)

        ID3D11DeviceContext_Release(device_hwctx->device_context);



    if (device_hwctx->video_device)

        ID3D11VideoDevice_Release(device_hwctx->video_device);



    if (device_hwctx->video_context)

        ID3D11VideoContext_Release(device_hwctx->video_context);



    if (device_hwctx->lock == d3d11va_default_lock)

        CloseHandle(device_hwctx->lock_ctx);

}
