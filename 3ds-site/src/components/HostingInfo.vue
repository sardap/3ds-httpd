<script setup lang="ts">
import { useI18n } from 'vue-i18n'
const { t } = useI18n({
  messages: {
    en: {
      intro_line: 'Yes this very site is hosted on the 2DS pictured above',
      three_ds_picture_alt: 'a photo of a 2DS',
      three_ds_picture_caption: 'Also this photo was taken on a 3DS',
      disclaimer_title: 'Disclaimer',
      disclaimer: `I didn't write the {0} that was made by {1}. I have made some minor changes and of course this site which can be found {2}.`,
      httpd_link_text: 'http-server',
      dimaguy_link_text: 'dimaguy',
      fork_link_text: 'here',
      where_is_the_3ds_title: 'Where is the 3ds?',
      where_is_the_3ds: `Where is the 3ds? The 3ds is inside of my house under the stars plugged. I then have a server
      running here with a wireguard VPN setup with a connection to the nginx server hosted in
      singapore. This site is built in vue and vite with a plugin so it creates a single html file.`,
      specs_title: 'What are the specs of the beast running this?',
    },
    kr: {
      intro_line: '위 사진에 나와 있는 2DS에서 이 사이트가 호스팅되고 있습니다.',
      three_ds_picture_alt: '2DS의 사진',
      three_ds_picture_caption: '이 사진은 3DS로 찍혔습니다.',
      disclaimer_title: '면책 조항',
      disclaimer: `{0}은 제가 작성한 것이 아니며 {1}가 만든 것입니다. 저는 약간의 변경을 했고, 이 사이트를 제작했으며, {2}에서 확인할 수 있습니다.`,
      httpd_link_text: 'http-server',
      dimaguy_link_text: 'dimaguy',
      fork_link_text: '여기',
      where_is_the_3ds_title: '3DS는 어디에 있나요?',
      where_is_the_3ds: `3DS는 제 집 안에 별 아래에 꽂혀 있습니다. 그곳에서 서버를 실행하며,
  wireguard VPN을 설정하고 싱가포르에 호스팅된 nginx 서버에 연결되어 있습니다.
  이 사이트는 vue와 vite로 제작되었으며 단일 HTML 파일을 생성하는 플러그인을 사용합니다.`,
      specs_title: '이걸 실행하는 괴물의 사양은 무엇인가요?',
    },
  },
})
</script>

<template>
  <div>
    <p>{{ t('intro_line') }}</p>
    <div>
      <img :alt="t('three_ds_picture_alt')" src="/2ds.jpg" />
      <p>{{ t('three_ds_picture_caption') }}</p>
    </div>
    <br />
    <h3>{{ t('disclaimer_title') }}</h3>
    <i18n-t keypath="disclaimer" tag="label">
      <a href="https://github.com/dimaguy/3ds-httpd" target="_blank">{{ t('httpd_link_text') }}</a>
      <a href="https://github.com/dimaguy" target="_blank">{{ t('dimaguy') }}</a>
      <a href="https://github.com/sardap/3ds-httpd" target="_blank">{{ t('fork_link_text') }}</a>
    </i18n-t>
    <br />
    <h3>{{ t('where_is_the_3ds_title') }}</h3>
    <p>{{ t('where_is_the_3ds') }}</p>
    <br />
    <h3>{{ t('specs_title') }}</h3>
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
h3 {
  margin-top: 20px;
}

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
