<script setup lang="ts"></script>

<template>
  <div>
    <p>Yes this very site is hosted on the 2DS pictured below</p>
    <div>
      <img alt="a photo of a 2DS" src="/2ds.jpg" />
      <p>Also this photo was taken on a 3DS</p>
    </div>
    <br />
    <p>
      I didn't write the
      <a target="_blank" href="https://github.com/dimaguy/3ds-httpd">http-server</a> that was made
      by <a target="_blank" href="https://github.com/dimaguy">dimaguy</a>. I have made some minor
      changes and of course this site which can be found
      <a target="_blank" href="https://github.com/sardap/3ds-httpd">here</a>.
    </p>
    <br />
    <p>
      Where is the 3ds? The 3ds is inside of my house under the stars plugged. I then have a server
      running here with a wireguard VPN setup with a connection to the nginx server hosted in
      singapore. This site is built in vue and vite with a plugin so it creates a single html file.
    </p>
    <br />
    <p>What are the specs of the beast running this?</p>
    <table>
      <tbody>
        <tr>
          <td>CPU</td>
          <td>Dual-core ARM11 MPCore @ 268 MHz</td>
        </tr>
        <tr>
          <td>Memory</td>
          <td>128MB FCRAM</td>
        </tr>
      </tbody>
    </table>
  </div>
</template>

<style scoped>
table {
  border: 1px solid black;
  margin: 0px auto;
}

td {
  border: 1px solid black;
}

img {
  max-width: 90%;
}
</style>
